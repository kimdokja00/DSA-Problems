from playwright.sync_api import sync_playwright
import os
import re
import subprocess
import sys
import time

GRAPHQL_URL = "https://leetcode.com/graphql"

# Number of submissions requested per batch
PAGE_SIZE = 20

# Maximum submission history to scan
MAX_SUBMISSIONS = 2000

# Your local Git repository
REPO_DIR = os.path.abspath("leetcode-solutions")


# =========================================================
# Language → file extension
# =========================================================

LANG_EXTENSIONS = {
    "cpp": ".cpp",
    "c++": ".cpp",

    "java": ".java",

    "python": ".py",
    "python3": ".py",

    "c": ".c",

    "javascript": ".js",
    "typescript": ".ts",

    "csharp": ".cs",
    "c#": ".cs",

    "go": ".go",
    "golang": ".go",

    "kotlin": ".kt",

    "rust": ".rs",

    "php": ".php",

    "swift": ".swift",

    "ruby": ".rb",

    "scala": ".scala",

    "dart": ".dart",

    "mysql": ".sql",
    "mssql": ".sql",
    "oracle": ".sql",
    "postgresql": ".sql",

    "bash": ".sh",
    "shell": ".sh",
}


# =========================================================
# Git helper
# =========================================================

def git(command):

    result = subprocess.run(
        command,
        cwd=REPO_DIR,
        text=True,
        capture_output=True
    )

    if result.returncode != 0:

        print("\nGit error:")
        print(result.stderr)

        sys.exit(1)

    return result.stdout.strip()


# =========================================================
# Make Windows-safe folder names
# =========================================================

def safe_name(name):

    return re.sub(
        r'[<>:"/\\|?*]',
        '',
        name
    )


# =========================================================
# GraphQL helper
# =========================================================

def graphql(page, query, variables=None):

    response = page.request.post(
        GRAPHQL_URL,
        data={
            "query": query,
            "variables": variables or {}
        },
        headers={
            "Content-Type": "application/json"
        }
    )

    if response.status != 200:

        print("\nLeetCode API error:")
        print("Status:", response.status)
        print(response.text())

        sys.exit(1)

    data = response.json()

    if "errors" in data:

        print("\nGraphQL error:")
        print(data["errors"])

        sys.exit(1)

    return data["data"]


# =========================================================
# Start Playwright
# =========================================================

with sync_playwright() as p:

    # -----------------------------------------------------
    # Connect to already-running Brave
    # -----------------------------------------------------

    try:

        browser = p.chromium.connect_over_cdp(
            "http://127.0.0.1:9222"
        )

    except Exception:

        print("""
Could not connect to Brave.

Start Brave with:

brave.exe --remote-debugging-port=9222 --user-data-dir="$env:USERPROFILE\\brave-leetcode-profile"

Then log into LeetCode and run this script again.
""")

        sys.exit(1)

    if not browser.contexts:

        print("No Brave browser context found.")

        sys.exit(1)

    context = browser.contexts[0]

    if not context.pages:

        print("No Brave pages found.")

        sys.exit(1)

    page = context.pages[0]


    # =====================================================
    # Check LeetCode login
    # =====================================================

    USER_QUERY = """
    query {
        userStatus {
            username
            isSignedIn
        }
    }
    """

    user_data = graphql(
        page,
        USER_QUERY
    )

    user = user_data["userStatus"]

    if not user["isSignedIn"]:

        print("""
You are not logged into LeetCode.

Open LeetCode in the Brave window,
log in, then run this script again.
""")

        sys.exit(1)

    username = user["username"]

    print("=" * 60)
    print("LeetCode user:", username)
    print("=" * 60)


    # =====================================================
    # Check repository
    # =====================================================

    if not os.path.isdir(REPO_DIR):

        print("\nRepository folder not found:")
        print(REPO_DIR)

        sys.exit(1)


    # =====================================================
    # Pull latest GitHub changes
    # =====================================================

    print("\nUpdating local repository...")

    result = subprocess.run(
        [
            "git",
            "pull",
            "--rebase",
            "origin",
            "main"
        ],
        cwd=REPO_DIR,
        text=True,
        capture_output=True
    )

    if result.returncode != 0:

        print("\nGit pull failed:")
        print(result.stderr)

        sys.exit(1)


    # =====================================================
    # Submission history query
    # =====================================================

    SUBMISSION_QUERY = """
    query submissionList(
        $offset: Int!
        $limit: Int!
        $lastKey: String
    ) {

        submissionList(
            offset: $offset
            limit: $limit
            lastKey: $lastKey
        ) {

            lastKey
            hasNext

            submissions {

                id
                statusDisplay
                lang
                timestamp
            }
        }
    }
    """


    # =====================================================
    # Fetch submission history
    # =====================================================

    print("\nFetching LeetCode submission history...")

    all_submissions = []

    offset = 0
    last_key = None

    while len(all_submissions) < MAX_SUBMISSIONS:

        print(
            f"Fetching submissions "
            f"{offset + 1}-{offset + PAGE_SIZE}..."
        )

        try:

            result = graphql(
                page,
                SUBMISSION_QUERY,
                {
                    "offset": offset,
                    "limit": PAGE_SIZE,
                    "lastKey": last_key
                }
            )

        except SystemExit:

            print(
                "\nCould not fetch submission history."
            )

            sys.exit(1)

        submission_list = result["submissionList"]

        submissions = submission_list["submissions"]

        if not submissions:

            break

        all_submissions.extend(submissions)

        print(
            f"  Received {len(submissions)} submissions"
        )

        if not submission_list["hasNext"]:

            break

        last_key = submission_list["lastKey"]

        offset += PAGE_SIZE

        time.sleep(0.5)


    print(
        f"\nTotal submissions found: "
        f"{len(all_submissions)}"
    )


    # =====================================================
    # Only accepted submissions
    # =====================================================

    accepted = [
        submission
        for submission in all_submissions
        if submission["statusDisplay"] == "Accepted"
    ]

    print(
        f"Accepted submissions: "
        f"{len(accepted)}"
    )


    # =====================================================
    # Submission details query
    # =====================================================

    DETAIL_QUERY = """
    query submissionDetails($submissionId: Int!) {

        submissionDetails(
            submissionId: $submissionId
        ) {

            code

            lang {
                name
            }

            question {
                title
                titleSlug
            }
        }
    }
    """


    downloaded = 0
    skipped = 0


    # =====================================================
    # Process every accepted submission
    # =====================================================

    for submission in accepted:

        submission_id = int(
            submission["id"]
        )

        print(
            f"\nChecking submission: "
            f"{submission_id}"
        )

        try:

            detail_data = graphql(
                page,
                DETAIL_QUERY,
                {
                    "submissionId": submission_id
                }
            )

        except Exception:

            print(
                "  Could not retrieve details."
            )

            continue

        details = detail_data.get(
            "submissionDetails"
        )

        if not details:

            print(
                "  No submission details."
            )

            continue

        code = details.get("code")

        question = details.get("question")

        language_info = details.get("lang")


        if not code:

            print(
                "  Source code unavailable."
            )

            continue

        if not question:

            print(
                "  Problem information unavailable."
            )

            continue

        if not language_info:

            print(
                "  Language information unavailable."
            )

            continue


        title = question["title"]

        slug = question["titleSlug"]

        language = language_info["name"].lower()


        # =================================================
        # Determine extension
        # =================================================

        extension = LANG_EXTENSIONS.get(
            language
        )

        if extension is None:

            print(
                f"  Unsupported language: "
                f"{language}"
            )

            continue


        # =================================================
        # Problem folder
        # =================================================

        folder_name = safe_name(slug)

        folder = os.path.join(
            REPO_DIR,
            folder_name
        )

        os.makedirs(
            folder,
            exist_ok=True
        )


        # =================================================
        # Every submission gets its own filename
        # =================================================

        file_name = (
            str(submission_id)
            + extension
        )

        solution_file = os.path.join(
            folder,
            file_name
        )


        # =================================================
        # Already synced?
        # =================================================

        if os.path.exists(solution_file):

            print(
                f"  Already synced: "
                f"{title}"
            )

            skipped += 1

            continue


        # =================================================
        # Save code
        # =================================================

        with open(
            solution_file,
            "w",
            encoding="utf-8"
        ) as file:

            file.write(code)


        print(
            f"  NEW: {title}"
        )

        print(
            f"  Language: {language}"
        )

        print(
            f"  Saved: {file_name}"
        )

        downloaded += 1


        # Be gentle with LeetCode
        time.sleep(0.5)


    # =====================================================
    # GitHub synchronization
    # =====================================================

    print("\n" + "=" * 60)

    print(
        f"New files: {downloaded}"
    )

    print(
        f"Already synced: {skipped}"
    )


    # =====================================================
    # Nothing new
    # =====================================================

    if downloaded == 0:

        print(
            "\nEverything is already synchronized."
        )

        print("=" * 60)

        sys.exit(0)


    # =====================================================
    # Git add
    # =====================================================

    print("\nAdding files to Git...")

    git([
        "git",
        "add",
        "."
    ])


    # =====================================================
    # Git commit
    # =====================================================

    print("Creating commit...")

    result = subprocess.run(
        [
            "git",
            "commit",
            "-m",
            "Add LeetCode questions"
        ],
        cwd=REPO_DIR,
        text=True,
        capture_output=True
    )


    if result.returncode != 0:

        print(
            result.stdout
        )

        print(
            result.stderr
        )

        sys.exit(1)


    # =====================================================
    # Git push
    # =====================================================

    print("Pushing to GitHub...")

    result = subprocess.run(
        [
            "git",
            "push",
            "origin",
            "main"
        ],
        cwd=REPO_DIR,
        text=True,
        capture_output=True
    )


    if result.returncode != 0:

        print("\nGit push failed:")

        print(
            result.stderr
        )

        sys.exit(1)


    # =====================================================
    # Done
    # =====================================================

    print("\n" + "=" * 60)

    print("SUCCESS!")

    print(
        f"{downloaded} new submission(s) "
        f"pushed to GitHub."
    )

    print(
        "Commit: Add LeetCode questions"
    )

    print("=" * 60)

    input(
        "\nPress Enter to finish..."
    )
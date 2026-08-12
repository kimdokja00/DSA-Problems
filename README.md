# LeetCode → GitHub Automation 🚀

Automatically sync your **accepted LeetCode submissions** to your own GitHub repository using **Python, Playwright, Brave, and Git**.

No LeetHub required.

The script connects to your manually authenticated Brave browser session, retrieves your accepted submissions from LeetCode, saves the source code locally, and automatically commits and pushes the changes to your GitHub repository.

---

## ✨ Features

* 🔄 Automatically sync accepted LeetCode submissions
* 🌐 Supports multiple programming languages
* 💾 Preserves multiple accepted submissions for the same problem
* 🆔 Uses the LeetCode submission ID as the filename
* 📁 Automatically creates problem folders
* 🚫 Skips submissions already synchronized
* 📤 Automatically commits and pushes to GitHub
* 🔐 Does not store your LeetCode password
* 🔑 Uses your existing Git authentication
* 🧩 Works with any GitHub repository
* 🆓 No third-party GitHub extension required

---

# 📂 Repository Structure

Put `leetcode_script.py` directly inside your own GitHub repository:

```text
your-dsa-repository/
│
├── leetcode_script.py
├── README.md
│
├── two-sum/
│   ├── 2091234567.cpp
│   └── 2091234568.py
│
├── valid-parentheses/
│   └── 2091234569.cpp
│
├── reverse-linked-list/
│   └── 2091234570.cpp
│
└── ...
```

The script automatically detects the repository folder where `leetcode_script.py` is located.

You do **not** need to modify the repository name or GitHub username in the script.

---

# 🛠️ Requirements

Install the following:

* Python 3
* Git
* Brave Browser
* LeetCode account
* GitHub account

Check Python:

```powershell
python --version
```

Check Git:

```powershell
git --version
```

---

# 1. Install Playwright

Open PowerShell:

```powershell
pip install playwright
```

The script uses your installed Brave browser, so you do not need to install another Chromium browser.

---

# 2. Use Your Existing GitHub Repository

You can use an existing repository or create a new one.

If you're setting it up on a new computer, clone your repository:

```powershell
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git
```

Then enter the repository:

```powershell
cd YOUR_REPOSITORY
```

Place `leetcode_script.py` inside this folder.

For example:

```text
my-dsa-repository/
├── leetcode_script.py
├── README.md
├── two-sum/
└── ...
```

### Important

You **do not need to create a separate repository** for the automation.

The script adds solutions to whichever Git repository contains `leetcode_script.py`.

---

# 3. GitHub Authentication

Make sure Git is configured:

```powershell
git config --global user.name "YOUR_GITHUB_USERNAME"
```

```powershell
git config --global user.email "YOUR_GITHUB_EMAIL"
```

Check:

```powershell
git config --global --list
```

Test your repository:

```powershell
git remote -v
```

You should see your own GitHub repository.

The script uses normal Git commands:

```text
git add
git commit
git push
```

You may need to authenticate GitHub the first time you push.

**Never put your GitHub password, token, or credentials inside `leet2.py`.**

---

# 4. Start Brave With Remote Debugging

Close all Brave windows first.

Open PowerShell and run:

```powershell
& "C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe" --remote-debugging-port=9222 --user-data-dir="$env:USERPROFILE\brave-leetcode-profile"
```

If Brave is installed somewhere else, change the path to your `brave.exe`.

For example:

```powershell
& "C:\Program Files (x86)\BraveSoftware\Brave-Browser\Application\brave.exe" --remote-debugging-port=9222 --user-data-dir="$env:USERPROFILE\brave-leetcode-profile"
```

---

# 5. Login to LeetCode

In the Brave window:

1. Open LeetCode.
2. Click **Sign In**.
3. Log into your account normally.
4. Keep the Brave window open.

The script does **not** ask for or store your LeetCode password.

---

# 6. Run the Automation

Open PowerShell inside your repository:

```powershell
cd "PATH_TO_YOUR_REPOSITORY"
```

Then:

```powershell
python leetcode_script.py
```

The script will automatically:

```text
LeetCode
   ↓
Find accepted submissions
   ↓
Get source code
   ↓
Create problem folder
   ↓
Save solution
   ↓
git add .
   ↓
git commit
   ↓
git push
   ↓
GitHub
```

---

# 📁 Multiple Solutions

If you submit the same problem multiple times and each submission is accepted, all submissions are preserved.

Example:

```text
two-sum/
├── 2091234567.cpp
├── 2091237890.cpp
└── 2091240001.cpp
```

The submission ID is used as the filename, so one solution does not overwrite another.

---

# 🌐 Supported Languages

The automation supports common LeetCode languages, including:

| Language   | Extension |
| ---------- | --------- |
| C          | `.c`      |
| C++        | `.cpp`    |
| Java       | `.java`   |
| Python     | `.py`     |
| JavaScript | `.js`     |
| TypeScript | `.ts`     |
| C#         | `.cs`     |
| Go         | `.go`     |
| Kotlin     | `.kt`     |
| Rust       | `.rs`     |
| PHP        | `.php`    |
| Swift      | `.swift`  |
| Ruby       | `.rb`     |
| Scala      | `.scala`  |
| Dart       | `.dart`   |
| SQL        | `.sql`    |
| Bash       | `.sh`     |

---

# 🔄 Daily Workflow

Once everything is configured:

### 1. Start Brave

```powershell
brave.exe --remote-debugging-port=9222 --user-data-dir="$env:USERPROFILE\brave-leetcode-profile"
```

### 2. Login to LeetCode

Only required if your session has expired.

### 3. Solve a problem

Submit your solution and get:

```text
Accepted ✅
```

### 4. Run:

```powershell
python leetcode_script.py
```

### 5. Done 🎉

The new solution will be pushed to your GitHub repository automatically.

---

# 📝 Git Commit

The automation uses:

```text
Add LeetCode questions
```

as the commit message.

Example:

```text
Add LeetCode questions
```

You don't need to manually run:

```powershell
git add .
git commit
git push
```

The script does it for you.

---

# 🔐 Security

This project does not require your LeetCode password.

Authentication works through your manually logged-in Brave session.

The script also does not require giving a third-party browser extension access to your GitHub repositories.

### Never commit:

```text
passwords
GitHub tokens
session cookies
browser profiles
API keys
```

Do not upload your Brave profile directory to GitHub.

---

# ⚠️ Troubleshooting

## Brave connection error

If you see:

```text
Could not connect to Brave
```

make sure Brave was started with:

```text
--remote-debugging-port=9222
```

Then run the script again.

---

## LeetCode login error

If you see:

```text
You are not logged into LeetCode
```

open LeetCode in the Brave window and log in again.

---

## Git push error

Check your remote:

```powershell
git remote -v
```

Make sure it points to **your own GitHub repository**.

Then test:

```powershell
git push
```

---

## Repository not detected

Make sure `leetcode_script.py` is located inside your Git repository:

```text
your-repository/
├── leetcode_script.py
├── README.md
└── ...
```

The script automatically detects its own directory as the repository.

---

# 🤝 Using This With Your Own Repository

You can use this automation with **any GitHub repository**.

For example:

```text
GitHub:
username1/leetcode
username2/dsa
username3/coding-solutions
```

Each person simply puts:

```text
leetcode_script.py
```

inside their own repository.

The script automatically pushes to that repository's configured Git remote.

No username or repository name needs to be hard-coded.

---

# 🎯 Why This Project?

This automation makes it easier to:

* Track LeetCode progress
* Back up solutions
* Practice Git and GitHub
* Preserve different approaches
* Maintain a coding portfolio
* Avoid manually copying solutions
* Avoid giving third-party extensions unnecessary GitHub access

---

# ⭐ Workflow

```text
             LEETCODE
                 │
                 ▼
           Solve Problem
                 │
                 ▼
             Accepted
                 │
                 ▼
          Logged-in Brave
                 │
                 ▼
        leetcode_script.py
                 │
                 ▼
          Fetch Source Code
                 │
                 ▼
          Your Git Repository
                 │
                 ▼
              Git Add
                 │
                 ▼
             Git Commit
                 │
                 ▼
              Git Push
                 │
                 ▼
              GITHUB 🚀
```

## License

Feel free to modify and use this automation for your own learning and coding workflow.

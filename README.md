# DSA-Problems

My personal collection of **LeetCode solutions and DSA practice**, automatically synchronized to GitHub.

The project uses **Python + Playwright + Brave + Git** to fetch accepted LeetCode submissions and push them to this repository.

---

# 🚀 Complete Setup

## 1. Requirements

Install:

* Python 3
* Git
* Brave Browser
* A GitHub account
* A LeetCode account

Check Python:

```powershell
python --version
```

Check Git:

```powershell
git --version
```

---

# 2. Install Python Package

Open PowerShell:

```powershell
pip install playwright
```

No separate Chromium installation is required because the script uses Brave.

---

# 3. Clone This Repository

Choose a location for the project.

Example:

```powershell
cd "C:\Users\harsh\Desktop"
```

Clone the repository:

```powershell
git clone https://github.com/kimdokja00/DSA-Problems.git
```

Go inside it:

```powershell
cd DSA-Problems
```

---

# 4. Create the LeetCode Automation Folder

The Python automation script should be kept separately from the repository.

Example:

```text
Desktop/
│
├── leet script/
│   └── leet2.py
│
└── DSA-Problems/
    ├── README.md
    └── ...
```

The script's repository path should point to the local `DSA-Problems` folder.

---

# 5. GitHub Authorization

The script uses Git to push solutions to GitHub.

Configure your Git identity:

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

When you perform your first push, GitHub may ask you to authenticate.

**Do not put your GitHub password inside `leet2.py`.**

After Git authentication is configured, the script can automatically:

```text
git add .
git commit
git push
```

---

# 6. Start Brave With Remote Debugging

The automation connects to a Brave browser session that you control.

First, close all Brave windows.

Then open PowerShell:

```powershell
& "C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe" --remote-debugging-port=9222 --user-data-dir="$env:USERPROFILE\brave-leetcode-profile"
```

If Brave is installed in another location, use its actual `brave.exe` path.

---

# 7. Login to LeetCode

Brave will open.

Go to:

```text
https://leetcode.com/
```

Click **Sign In** and log into your LeetCode account normally.

You can use your normal LeetCode login method.

The Python script does **not** need your LeetCode password.

Keep this Brave window open while running the script.

---

# 8. Test the LeetCode Connection

Make sure Brave is running with:

```text
--remote-debugging-port=9222
```

Then run:

```powershell
python leet2.py
```

The script should detect your logged-in LeetCode account.

You should see something similar to:

```text
============================================================
LeetCode user: YOUR_USERNAME
============================================================
```

---

# 9. Repository Configuration

The script expects the local Git repository to be:

```text
leetcode-solutions/
```

If your repository folder has a different name, change:

```python
REPO_DIR = os.path.abspath("leetcode-solutions")
```

to the actual location.

For example:

```python
REPO_DIR = r"C:\Users\harsh\Desktop\DSA-Problems"
```

This is recommended if the script is stored outside the repository.

---

# 10. First Synchronization

After logging into LeetCode:

```powershell
python leet2.py
```

The script will:

```text
Connect to Brave
       ↓
Check LeetCode login
       ↓
Fetch submission history
       ↓
Find Accepted submissions
       ↓
Download source code
       ↓
Create problem folders
       ↓
Save solutions
       ↓
git add .
       ↓
git commit
       ↓
git push
```

---

# 📁 Repository Structure

For example:

```text
DSA-Problems/
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
├── generate-parentheses/
│   └── 2091234571.cpp
│
└── README.md
```

The folder name is the LeetCode problem slug.

The filename is the **submission ID**.

---

# 🔄 Multiple Submissions

If you submit the same problem multiple times, every accepted submission is preserved.

Example:

```text
two-sum/
├── 2091234567.cpp
├── 2091237890.cpp
└── 2091240001.cpp
```

This prevents one solution from overwriting another.

If the same problem is solved in different languages:

```text
two-sum/
├── 2091234567.cpp
├── 2091237890.cpp
└── 2091240001.py
```

---

# 🌐 Supported Languages

The automation supports common LeetCode languages:

* C
* C++
* Java
* Python
* JavaScript
* TypeScript
* C#
* Go
* Kotlin
* Rust
* PHP
* Swift
* Ruby
* Scala
* Dart
* SQL
* Bash

---

# 📝 Automatic Git Commit

Every synchronization creates the commit:

```text
Add LeetCode questions
```

For example:

```text
Add LeetCode questions
```

The script then pushes automatically to:

```text
main
```

---

# 🧑‍💻 Normal Daily Workflow

Once everything is configured, your workflow is very simple.

### Step 1

Start Brave:

```powershell
& "C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe" --remote-debugging-port=9222 --user-data-dir="$env:USERPROFILE\brave-leetcode-profile"
```

### Step 2

Make sure you're logged into LeetCode.

### Step 3

Solve problems on LeetCode.

### Step 4

After getting an **Accepted** submission:

```powershell
python leet2.py
```

### Step 5

The script automatically uploads the new solutions to GitHub.

---

# 🔐 Security

The project does not store your:

* LeetCode password
* GitHub password

The LeetCode login is performed manually in Brave.

The script connects to the already authenticated browser session.

Git handles GitHub authentication.

**Never add passwords, cookies, session tokens, or GitHub tokens to this repository.**

---

# ⚠️ Important

Keep the Brave window running with:

```text
--remote-debugging-port=9222
```

while using the script.

If the script says:

```text
Could not connect to Brave
```

restart Brave using the command from the setup section.

If the script says:

```text
You are not logged into LeetCode
```

open LeetCode in the Brave window and log in again.

---

# 🎯 Purpose

This project helps me:

* Track my LeetCode progress
* Automatically back up solutions
* Practice DSA
* Learn Git and GitHub
* Preserve multiple solutions
* Build a public coding portfolio

---

## ⭐ Workflow

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
                  BRAVE SESSION
                       │
                       ▼
                 Python Script
                       │
                       ▼
              Fetch Source Code
                       │
                       ▼
                 DSA-Problems
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
                    GITHUB
```

**Solve → Submit → Sync → GitHub 🚀**

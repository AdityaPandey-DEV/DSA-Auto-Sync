# 🤖 Automation Scripts

## Overview

This folder contains automation scripts for managing and syncing solutions across different competitive programming platforms. These scripts help maintain the repository, organize problems, and track progress automatically.

---

## 📁 Scripts

### 1. `cf_sync.sh` - Codeforces Synchronization

**Purpose:** Automatically syncs Codeforces solutions to the repository.

**Features:**
- Checks for new Codeforces solution files
- Automatically commits changes with timestamp
- Pushes to remote repository
- Provides status feedback

**Usage:**
```bash
bash scripts/cf_sync.sh
```

**What it does:**
1. Scans the `codeforces/` directory for changes
2. If changes found, stages all Codeforces files
3. Creates a commit with current date
4. Pushes to remote repository
5. Displays success/status messages

**Example Output:**
```
🔵 Syncing Codeforces solutions...
🚀 Codeforces solutions synced successfully!
```

---

### 2. `gfg_sync.sh` - GeeksforGeeks Synchronization

**Purpose:** Automatically syncs GeeksforGeeks solutions to the repository.

**Features:**
- Checks for new GFG solution files
- Automatically commits changes with timestamp
- Pushes to remote repository
- Provides status feedback

**Usage:**
```bash
bash scripts/gfg_sync.sh
```

**What it does:**
1. Scans the `geeksforgeeks/` directory for changes
2. If changes found, stages all GFG files
3. Creates a commit with current date
4. Pushes to remote repository
5. Displays success/status messages

**Example Output:**
```
🟢 Syncing GeeksforGeeks solutions...
🚀 GeeksforGeeks solutions synced successfully!
```

---

### 3. `count_problems.py` - Problem Counter

**Purpose:** Counts the number of solution files across all platforms and generates statistics.

**Features:**
- Recursively counts solution files (.cpp, .py, .java)
- Generates statistics for LeetCode, Codeforces, and GFG
- Outputs to `stats.json` file

**Usage:**
```bash
python scripts/count_problems.py
```

**What it does:**
1. Walks through `leetcode/`, `codeforces/`, and `geeksforgeeks/` directories
2. Counts all files with extensions: `.cpp`, `.py`, `.java`
3. Stores counts in a dictionary format
4. Writes statistics to `stats.json`

**Output Format:**
```json
{
  "leetcode": 327,
  "codeforces": 112,
  "geeksforgeeks": 64
}
```

**Integration:**
- Can be integrated with CI/CD pipelines
- Used to update README badges
- Powers dashboard statistics

---

### 4. `organize_leetcode_by_readme.py` - Organize Problems by README Difficulty

**Purpose:** Automatically organizes LeetCode problems by difficulty by reading from README.md files.

**Features:**
- Scans all problem folders in `leetcode/` directory
- Extracts difficulty from README.md files (HTML format)
- Moves folders to appropriate difficulty directories (easy/, medium/, hard/)
- Handles multiple HTML formats for difficulty detection
- Skips folders already organized or without README
- Provides detailed statistics and logging

**Usage:**
```bash
python scripts/organize_leetcode_by_readme.py
```

**What it does:**
1. Scans `leetcode/` directory for problem folders (excludes easy/, medium/, hard/)
2. For each problem folder:
   - Checks if `README.md` exists
   - Reads first few lines to extract difficulty from HTML format
   - Parses patterns like: `alt='Difficulty: Medium'` or `<img alt="Difficulty: Hard" />`
   - Determines target directory based on difficulty
   - Checks if folder already in correct location (skips if yes)
   - Moves folder to appropriate difficulty directory
3. Provides summary with counts for each difficulty level
4. Returns exit code 0 if changes made, 0 if no changes needed

**Supported HTML Formats:**
- `<img alt='Difficulty: Medium' />`
- `<img alt="Difficulty: Medium" />`
- `alt='Easy'` or `alt="Hard"`
- Markdown format: `## Difficulty: Medium`

**Example Output:**
```
📁 Found 15 problem folders to process

✅ Moved 896-smallest-subtree-with-all-the-deepest-nodes → medium/
✅ Moved 1-two-sum → easy/
⏭️  Skipping 2-add-two-numbers (already in difficulty folder)
⚠️  Skipping 3-longest-substring (could not extract difficulty)

📊 Summary:
  ✅ Easy: 3
  ✅ Medium: 8
  ✅ Hard: 2
  ⏭️  Skipped: 2
  ❌ Errors: 0

✅ Changes made! Please commit the changes.
```

**Error Handling:**
- Handles missing README.md files gracefully
- Skips folders with invalid difficulty formats
- Prevents overwriting existing folders
- Logs all warnings and errors
- Continues processing remaining problems even if some fail

**Integration:**
- Used by GitHub Actions workflow (`.github/workflows/organize-leetcode.yml`)
- Runs daily via cron schedule
- Triggers on push to main branch (leetcode/ directory changes)
- Can be manually triggered via workflow_dispatch
- Automatically commits and pushes changes

**Prerequisites:**
- Python 3.6+
- Problem folders must have README.md with difficulty information in HTML format

---

### 5. `update_readme_stats.py` - README Statistics Updater

**Purpose:** Updates all README files with real-time problem statistics from all platforms.

**Features:**
- Counts problems from LeetCode, Codeforces, and GeeksforGeeks
- Updates main README.md with total counts and badges
- Updates leetcode/README.md with total + difficulty breakdown
- Updates codeforces/README.md with total count
- Updates geeksforgeeks/README.md with total count
- Automatically updates badge URLs with correct counts
- Handles both file-based and folder-based problem organization

**Usage:**
```bash
python scripts/update_readme_stats.py
```

**What it does:**
1. Counts LeetCode problems by difficulty (easy, medium, hard) and total
2. Counts Codeforces solution files
3. Counts GeeksforGeeks solution files
4. Updates badges in all README files with current counts
5. Updates statistics sections with breakdowns
6. Updates total count in main README Key Highlights section

**Example Output:**
```
📊 Counting problems from all platforms...

📈 Statistics:
  LeetCode: 327 total (150 easy, 150 medium, 27 hard)
  Codeforces: 112
  GeeksforGeeks: 64
  Total: 503

📝 Updating README files...

✅ Updated main README.md
✅ Updated leetcode/README.md
✅ Updated codeforces/README.md
✅ Updated geeksforgeeks/README.md

✅ All README files updated successfully!
```

**Error Handling:**
- Handles missing directories gracefully
- Skips files that don't exist
- Continues processing remaining files if one fails
- Provides detailed error messages

**Integration:**
- Used by GitHub Actions workflow (`.github/workflows/update-readme-stats.yml`)
- Runs daily at 01:00 UTC (after organize-leetcode workflow)
- Triggers on push to main branch (when solution files change)
- Can be manually triggered via workflow_dispatch
- Automatically commits and pushes changes

**Prerequisites:**
- Python 3.6+
- README files must exist in expected locations

---

### 6. `update_dashboard.py` - Dashboard Generator

**Purpose:** Generates a monthly progress dashboard showing problem-solving activity.

**Features:**
- Analyzes file modification timestamps
- Groups problems by month
- Generates markdown dashboard
- Shows platform-wise and overall statistics

**Usage:**
```bash
python scripts/update_dashboard.py
```

**What it does:**
1. Scans `leetcode/`, `codeforces/`, and `geeksforgeeks/` directories
2. Extracts modification timestamp from each solution file
3. Groups files by month (YYYY-MM format)
4. Counts problems per month per platform
5. Generates `dashboard.md` with formatted statistics

**Output Format:**
```markdown
# 📊 DSA Monthly Progress Dashboard

_Auto-updated on 15 Jan 2026_

## LeetCode
- **2026-01**: 45 problems
- **2026-02**: 52 problems

## Codeforces
- **2026-01**: 18 problems
- **2026-02**: 21 problems

## GeeksforGeeks
- **2026-01**: 10 problems
- **2026-02**: 8 problems

## 📈 Overall Monthly Progress
- **2026-01**: 73 problems
- **2026-02**: 81 problems
```

**Integration:**
- Can be scheduled via cron job
- Can be triggered by GitHub Actions
- Updates `dashboard.md` automatically

---

## ⚙️ Automation Workflow

### Manual Execution
Run scripts individually as needed:
```bash
# Sync solutions
bash scripts/cf_sync.sh
bash scripts/gfg_sync.sh

# Update statistics
python scripts/count_problems.py
python scripts/update_dashboard.py
python scripts/update_readme_stats.py  # Update README files with real-time stats

# Organize LeetCode (automated via GitHub Actions)
python scripts/organize_leetcode_by_readme.py  # Reads from README.md files
```

### GitHub Actions Integration
These scripts can be integrated into GitHub Actions workflows for automated:
- Daily syncing of solutions
- Weekly dashboard updates
- Problem counting and statistics
- Automatic organization

**Example Workflow:**
```yaml
name: Update Dashboard
on:
  schedule:
    - cron: '0 0 * * 0'  # Weekly
  workflow_dispatch:

jobs:
  update:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - uses: actions/setup-python@v2
      - run: python scripts/update_dashboard.py
      - run: python scripts/count_problems.py
      - uses: stefanzweifel/git-auto-commit-action@v4
```

---

## 🔧 Prerequisites

### System Requirements
- **Bash** - For shell scripts (Linux/macOS/WSL)
- **Python 3.6+** - For Python scripts
- **Git** - For version control operations

### Optional Dependencies
- **Python 3.6+** - For all Python scripts

### Permissions
Ensure scripts have execute permissions:
```bash
chmod +x scripts/*.sh
```

---

## 📝 Notes

- All scripts follow best practices with error handling
- Scripts are designed to be safe and non-destructive
- Status messages provide clear feedback
- Scripts can be run independently or in sequence
- Configuration can be modified in script files as needed

---

## 🐛 Troubleshooting

### Common Issues

**Issue:** `cf_sync.sh` or `gfg_sync.sh` says "No new solutions"
- **Solution:** This is expected if there are no uncommitted changes


**Issue:** Permission denied errors
- **Solution:** Run `chmod +x scripts/*.sh` to grant execute permissions

**Issue:** Python script errors
- **Solution:** Ensure Python 3.6+ is installed: `python3 --version`

---

## 📚 Related Resources

- [Main README](../README.md) - Repository overview
- [LeetCode Folder](../leetcode/README.md) - LeetCode solutions
- [Codeforces Folder](../codeforces/README.md) - Codeforces solutions
- [GeeksforGeeks Folder](../geeksforgeeks/README.md) - GFG solutions

---

_Last updated: Auto-maintained by scripts_


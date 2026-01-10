#!/bin/bash

# -----------------------------
# Codeforces Sync Script
# -----------------------------

set -e  # Exit immediately if a command fails

echo "🔵 Syncing Codeforces solutions..."

# Check if there are changes
if [[ -z $(git status --porcelain codeforces/) ]]; then
  echo "✅ No new Codeforces solutions to sync."
  exit 0
fi

# Add Codeforces files
git add codeforces/

# Commit with timestamp
git commit -m "Add Codeforces solutions ($(date '+%Y-%m-%d'))"

# Push to remote
git push

echo "🚀 Codeforces solutions synced successfully!"
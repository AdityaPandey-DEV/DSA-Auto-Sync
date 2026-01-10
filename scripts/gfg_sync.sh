#!/bin/bash

# -----------------------------
# GeeksforGeeks Sync Script
# -----------------------------

set -e  # Exit immediately if a command fails

echo "🟢 Syncing GeeksforGeeks solutions..."

# Check if there are changes
if [[ -z $(git status --porcelain geeksforgeeks/) ]]; then
  echo "✅ No new GFG solutions to sync."
  exit 0
fi

# Add GFG files
git add geeksforgeeks/

# Commit with timestamp
git commit -m "Add GeeksforGeeks solutions ($(date '+%Y-%m-%d'))"

# Push to remote
git push

echo "🚀 GeeksforGeeks solutions synced successfully!"
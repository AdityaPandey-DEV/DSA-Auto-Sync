#!/usr/bin/env python3
"""
Organize LeetCode problems by difficulty by reading from README.md files.

This script scans all problem folders in the leetcode/ directory,
extracts difficulty information from README.md files (HTML format),
and moves folders to appropriate difficulty directories (easy/, medium/, hard/).
"""

import os
import re
import shutil
import subprocess
import sys
from pathlib import Path


BASE_DIR = Path("leetcode")
EASY_DIR = BASE_DIR / "easy"
MEDIUM_DIR = BASE_DIR / "medium"
HARD_DIR = BASE_DIR / "hard"

# Folders to exclude from processing
EXCLUDED_FOLDERS = {"easy", "medium", "hard", ".git", "__pycache__"}


def extract_difficulty_from_readme(readme_path):
    """
    Extract difficulty from README.md file.
    
    Parses HTML format like:
    <h2><a href="...">Title</a></h2> <img src='...' alt='Difficulty: Medium' />
    or
    <img src='...' alt='Difficulty: Easy' />
    
    Args:
        readme_path: Path to README.md file
        
    Returns:
        str: 'easy', 'medium', 'hard', or None if not found
    """
    if not readme_path.exists():
        return None
    
    try:
        with open(readme_path, 'r', encoding='utf-8') as f:
            # Read first few lines (difficulty is usually in first line or early lines)
            first_lines = ''.join(f.readlines()[:5])
            
            # Pattern 1: Look for alt='Difficulty: Medium' or alt="Difficulty: Medium"
            pattern1 = r"alt=['\"]Difficulty:\s*(Easy|Medium|Hard)['\"]"
            match1 = re.search(pattern1, first_lines, re.IGNORECASE)
            if match1:
                difficulty = match1.group(1).lower()
                return difficulty
            
            # Pattern 2: Look for badge text like "Difficulty: Medium" or "Medium"
            pattern2 = r"Difficulty:\s*(Easy|Medium|Hard)"
            match2 = re.search(pattern2, first_lines, re.IGNORECASE)
            if match2:
                difficulty = match2.group(1).lower()
                return difficulty
            
            # Pattern 3: Look for difficulty in badge alt without "Difficulty:" prefix
            pattern3 = r"alt=['\"](Easy|Medium|Hard)['\"]"
            match3 = re.search(pattern3, first_lines, re.IGNORECASE)
            if match3:
                difficulty = match3.group(1).lower()
                return difficulty
            
            # Pattern 4: Look for markdown format like ## Difficulty: Medium
            pattern4 = r"#+\s*Difficulty:\s*(Easy|Medium|Hard)"
            match4 = re.search(pattern4, first_lines, re.IGNORECASE)
            if match4:
                difficulty = match4.group(1).lower()
                return difficulty
            
    except Exception as e:
        print(f"⚠️  Error reading {readme_path}: {e}", file=sys.stderr)
        return None
    
    return None


def get_target_directory(difficulty):
    """Get target directory based on difficulty."""
    difficulty_map = {
        'easy': EASY_DIR,
        'medium': MEDIUM_DIR,
        'hard': HARD_DIR
    }
    return difficulty_map.get(difficulty.lower())


def is_already_organized(folder_path):
    """Check if folder is already in a difficulty directory."""
    parent = folder_path.parent
    return parent.name.lower() in ['easy', 'medium', 'hard']


def organize_problems():
    """Main function to organize LeetCode problems by difficulty."""
    if not BASE_DIR.exists():
        print(f"❌ Directory {BASE_DIR} does not exist!", file=sys.stderr)
        return False, {"easy": 0, "medium": 0, "hard": 0, "skipped": 0, "errors": 0}
    
    # Ensure difficulty directories exist
    EASY_DIR.mkdir(parents=True, exist_ok=True)
    MEDIUM_DIR.mkdir(parents=True, exist_ok=True)
    HARD_DIR.mkdir(parents=True, exist_ok=True)
    
    stats = {"easy": 0, "medium": 0, "hard": 0, "skipped": 0, "errors": 0}
    changes_made = False
    
    # Get all folders and files in leetcode/ directory
    problem_folders = []
    problem_files = []
    
    for item in BASE_DIR.iterdir():
        if item.name in EXCLUDED_FOLDERS:
            continue
        if item.is_dir():
            problem_folders.append(item)
        elif item.is_file() and item.suffix in ['.cpp', '.py', '.java']:
            # Create a temporary folder structure for file-based problems
            problem_files.append(item)
    
    total_items = len(problem_folders) + len(problem_files)
    print(f"📁 Found {len(problem_folders)} problem folders and {len(problem_files)} problem files to process\n")
    
    for folder in sorted(problem_folders):
        folder_name = folder.name
        readme_path = folder / "README.md"
        
        # Check if already organized
        if is_already_organized(folder):
            print(f"⏭️  Skipping {folder_name} (already in difficulty folder)")
            stats["skipped"] += 1
            continue
        
        # Check if README.md exists
        if not readme_path.exists():
            print(f"⚠️  Skipping {folder_name} (no README.md found)")
            stats["skipped"] += 1
            continue
        
        # Extract difficulty from README
        difficulty = extract_difficulty_from_readme(readme_path)
        
        if not difficulty:
            print(f"⚠️  Skipping {folder_name} (could not extract difficulty)")
            stats["skipped"] += 1
            continue
        
        # Get target directory
        target_dir = get_target_directory(difficulty)
        if not target_dir:
            print(f"❌ Invalid difficulty '{difficulty}' for {folder_name}")
            stats["errors"] += 1
            continue
        
        # Check if target already exists - replace it with new solution
        target_path = target_dir / folder_name
        
        # Also check if problem exists in other difficulty folders and remove them
        for other_dir in [EASY_DIR, MEDIUM_DIR, HARD_DIR]:
            if other_dir != target_dir:
                other_path = other_dir / folder_name
                if other_path.exists():
                    print(f"🔄 Removing duplicate {folder_name} from {other_dir.name}/")
                    try:
                        # Try git rm first to preserve history
                        subprocess.run(
                            ["git", "rm", "-r", str(other_path)],
                            check=True,
                            capture_output=True,
                            text=True
                        )
                    except (subprocess.CalledProcessError, FileNotFoundError):
                        # Fallback to shutil if git not available
                        try:
                            shutil.rmtree(str(other_path))
                        except Exception as e:
                            print(f"⚠️  Warning: Could not remove from {other_dir.name}: {e}", file=sys.stderr)
        
        if target_path.exists():
            print(f"🔄 Replacing existing solution for {folder_name} in {difficulty}/")
            try:
                # Try git rm first to preserve history
                try:
                    subprocess.run(
                        ["git", "rm", "-r", str(target_path)],
                        check=True,
                        capture_output=True,
                        text=True
                    )
                    print(f"   Removed old solution (preserving git history)")
                except (subprocess.CalledProcessError, FileNotFoundError):
                    # Fallback to shutil if git not available
                    shutil.rmtree(str(target_path))
                    print(f"   Removed old solution")
            except Exception as e:
                print(f"⚠️  Warning: Could not remove existing folder: {e}", file=sys.stderr)
                # Continue anyway - will try to move and may overwrite
        
        # Move folder to target directory using git mv to preserve history
        try:
            # Use git mv to preserve commit history
            try:
                subprocess.run(
                    ["git", "mv", str(folder), str(target_path)],
                    check=True,
                    capture_output=True,
                    text=True
                )
                print(f"✅ Moved {folder_name} → {difficulty}/ (preserving git history)")
            except (subprocess.CalledProcessError, FileNotFoundError):
                # Fallback to shutil.move if git is not available or not in git repo
                shutil.move(str(folder), str(target_path))
                print(f"✅ Moved {folder_name} → {difficulty}/")
            
            stats[difficulty] += 1
            changes_made = True
        except Exception as e:
            print(f"❌ Error moving {folder_name}: {e}", file=sys.stderr)
            stats["errors"] += 1
    
    # Print summary
    print(f"\n📊 Summary:")
    print(f"  ✅ Easy: {stats['easy']}")
    print(f"  ✅ Medium: {stats['medium']}")
    print(f"  ✅ Hard: {stats['hard']}")
    print(f"  ⏭️  Skipped: {stats['skipped']}")
    print(f"  ❌ Errors: {stats['errors']}")
    
    return changes_made, stats


if __name__ == "__main__":
    try:
        changes_made, stats = organize_problems()
        
        if changes_made:
            print("\n✅ Changes made! Please commit the changes.")
            sys.exit(0)
        else:
            print("\n✅ No changes needed. All problems are already organized.")
            sys.exit(0)
            
    except KeyboardInterrupt:
        print("\n\n⚠️  Interrupted by user", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"\n❌ Unexpected error: {e}", file=sys.stderr)
        sys.exit(1)


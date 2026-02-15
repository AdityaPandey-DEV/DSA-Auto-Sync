#!/usr/bin/env python3
"""
Update README files with real-time problem statistics.

This script counts problems from each platform and updates:
- Main README.md with total counts
- leetcode/README.md with total + difficulty breakdown
- codeforces/README.md with total count
"""

import os
import re
import sys
from pathlib import Path


def count_solution_files(directory):
    """Count solution files (.cpp, .py, .java) in a directory recursively.

    For platforms like Codeforces, count all solution files.
    """
    if not os.path.exists(directory):
        return 0

    count = 0
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith((".cpp", ".py", ".java")):
                count += 1
    return count


def count_leetcode_by_difficulty():
    """Count LeetCode problems by difficulty level."""
    base_dir = Path("leetcode")
    stats = {"easy": 0, "medium": 0, "hard": 0, "total": 0}

    if not base_dir.exists():
        return stats

    # Count by difficulty folders
    for difficulty in ["easy", "medium", "hard"]:
        difficulty_dir = base_dir / difficulty
        if difficulty_dir.exists():
            # Count unique problems - either folders or files
            problem_set = set()
            for item in difficulty_dir.rglob("*"):
                if item.is_file() and item.suffix in [".cpp", ".py", ".java"]:
                    # Get the relative path from difficulty folder
                    rel_path = item.relative_to(difficulty_dir)
                    # If file is directly in difficulty folder, use filename stem
                    # If in subfolder, use the first folder name (problem folder)
                    if rel_path.parent == Path("."):
                        problem_name = rel_path.stem
                    else:
                        problem_name = str(rel_path.parts[0])
                    problem_set.add(problem_name)
            stats[difficulty] = len(problem_set)

    # Count problems not in difficulty folders (root level)
    # These are problem folders directly in leetcode/ directory
    root_problems = set()
    excluded = {"easy", "medium", "hard", ".git", "README.md"}

    for item in base_dir.iterdir():
        if item.name in excluded:
            continue

        if item.is_file() and item.suffix in [".cpp", ".py", ".java"]:
            # Direct file in root
            root_problems.add(item.stem)
        elif item.is_dir():
            # Problem folder - check if it contains solution files
            has_solutions = any(
                f.suffix in [".cpp", ".py", ".java"]
                for f in item.rglob("*")
                if f.is_file()
            )
            if has_solutions:
                root_problems.add(item.name)

    root_count = len(root_problems)

    # Total count (sum of all difficulty levels + root level problems)
    stats["total"] = stats["easy"] + stats["medium"] + stats["hard"] + root_count

    return stats


def update_leetcode_readme(leetcode_stats):
    """Update leetcode/README.md with statistics."""
    file_path = "leetcode/README.md"
    if not os.path.exists(file_path):
        print(f"⚠️  File not found: {file_path}")
        return False

    try:
        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()

        # Update total badge
        total_pattern = re.compile(
            r"(\!\[LeetCode Solved\]\()(https://img\.shields\.io/badge/Problems%20Solved-)(\d+)(-FFA116[^\]]+\))",
            re.IGNORECASE,
        )

        def replace_total(match):
            return f"{match.group(1)}{match.group(2)}{leetcode_stats['total']}{match.group(4)}"

        content = total_pattern.sub(replace_total, content)

        # Update breakdown section
        # Pattern matches: **Current Breakdown:**\n- Easy: X problems\n- Medium: Y problems\n- Hard: Z problems
        breakdown_pattern = re.compile(
            r"(\*\*Current Breakdown:\*\*\s*\n- Easy: )\d+( problems\s*\n- Medium: )\d+( problems\s*\n- Hard: )\d+( problems)",
            re.IGNORECASE | re.MULTILINE,
        )

        def replace_breakdown(match):
            return f"{match.group(1)}{leetcode_stats['easy']}{match.group(2)}{leetcode_stats['medium']}{match.group(3)}{leetcode_stats['hard']}{match.group(4)}"

        content = breakdown_pattern.sub(replace_breakdown, content)

        # Also try pattern without "problems" suffix (more flexible)
        breakdown_pattern2 = re.compile(
            r"(\*\*Current Breakdown:\*\*\s*\n- Easy: )\d+(\s*\n- Medium: )\d+(\s*\n- Hard: )\d+",
            re.IGNORECASE | re.MULTILINE,
        )

        def replace_breakdown2(match):
            return f"{match.group(1)}{leetcode_stats['easy']} problems{match.group(2)}{leetcode_stats['medium']} problems{match.group(3)}{leetcode_stats['hard']} problems"

        # Only apply second pattern if first didn't match
        if breakdown_pattern.search(content) is None:
            content = breakdown_pattern2.sub(replace_breakdown2, content)

        with open(file_path, "w", encoding="utf-8") as f:
            f.write(content)
        return True
    except Exception as e:
        print(f"❌ Error updating leetcode/README.md: {e}", file=sys.stderr)
        return False


def update_codeforces_readme(count):
    """Update codeforces/README.md with statistics."""
    file_path = "codeforces/README.md"
    if not os.path.exists(file_path):
        print(f"⚠️  File not found: {file_path}")
        return False

    try:
        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()

        # Update badge
        badge_pattern = re.compile(
            r"(\!\[Codeforces Solved\]\()(https://img\.shields\.io/badge/Problems%20Solved-)(\d+)(-1F8ACB[^\]]+\))",
            re.IGNORECASE,
        )

        def replace_badge(match):
            return f"{match.group(1)}{match.group(2)}{count}{match.group(4)}"

        content = badge_pattern.sub(replace_badge, content)

        with open(file_path, "w", encoding="utf-8") as f:
            f.write(content)
        return True
    except Exception as e:
        print(f"❌ Error updating codeforces/README.md: {e}", file=sys.stderr)
        return False




def update_main_readme(leetcode_count, codeforces_count):
    """Update main README.md with all statistics."""
    file_path = "README.md"
    if not os.path.exists(file_path):
        print(f"⚠️  File not found: {file_path}")
        return False

    try:
        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()

        # Update LeetCode badge
        leetcode_pattern = re.compile(
            r"(\!\[LeetCode\]\()(https://img\.shields\.io/badge/LeetCode-)(\d+)(-FFA116[^\]]+\))",
            re.IGNORECASE,
        )

        def replace_leetcode(match):
            return f"{match.group(1)}{match.group(2)}{leetcode_count}{match.group(4)}"

        content = leetcode_pattern.sub(replace_leetcode, content)

        # Update Codeforces badge
        cf_pattern = re.compile(
            r"(\!\[Codeforces\]\()(https://img\.shields\.io/badge/Codeforces-)(\d+)(-1F8ACB[^\]]+\))",
            re.IGNORECASE,
        )

        def replace_cf(match):
            return f"{match.group(1)}{match.group(2)}{codeforces_count}{match.group(4)}"

        content = cf_pattern.sub(replace_cf, content)

        # Update total in Key Highlights
        total = leetcode_count + codeforces_count
        total_pattern = re.compile(
            r"(- ✅ Solved \*\*)(\d+)(\+ DSA problems)", re.IGNORECASE
        )

        def replace_total(match):
            return f"{match.group(1)}{total}{match.group(3)}"

        content = total_pattern.sub(replace_total, content)

        with open(file_path, "w", encoding="utf-8") as f:
            f.write(content)
        return True
    except Exception as e:
        print(f"❌ Error updating main README.md: {e}", file=sys.stderr)
        return False


def main():
    """Main function to update all README files."""
    print("📊 Counting problems from all platforms...\n")

    # Count problems
    leetcode_stats = count_leetcode_by_difficulty()
    # For Codeforces, count all solution files
    codeforces_count = count_solution_files("codeforces")

    print(f"📈 Statistics:")
    print(
        f"  LeetCode: {leetcode_stats['total']} total ({leetcode_stats['easy']} easy, {leetcode_stats['medium']} medium, {leetcode_stats['hard']} hard)"
    )
    print(f"  Codeforces: {codeforces_count}")
    print(
        f"  Total: {leetcode_stats['total'] + codeforces_count}\n"
    )

    # Update README files
    changes_made = False

    print("📝 Updating README files...\n")

    if update_main_readme(
        leetcode_stats["total"], codeforces_count
    ):
        print("✅ Updated main README.md")
        changes_made = True

    if update_leetcode_readme(leetcode_stats):
        print("✅ Updated leetcode/README.md")
        changes_made = True

    if update_codeforces_readme(codeforces_count):
        print("✅ Updated codeforces/README.md")
        changes_made = True


    if changes_made:
        print("\n✅ All README files updated successfully!")
        sys.exit(0)
    else:
        print("\n✅ No changes needed. Statistics are already up to date.")
        sys.exit(0)


if __name__ == "__main__":
    main()

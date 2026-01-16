# 📝 LeetCode Solutions

## Overview

This folder contains solutions to LeetCode problems organized by difficulty level. All solutions are implemented in **C++** and **Python**, following best practices for competitive programming and technical interviews.

---

## 📊 Statistics

![LeetCode Solved](https://img.shields.io/badge/Problems%20Solved-28-FFA116?logo=leetcode&logoColor=black)

**Current Breakdown:**
- Easy: 9 problems
- Medium: 14 problems
- Hard: 5 problems

_Note: Statistics are auto-updated via scripts. Run `python scripts/count_problems.py` to update._

---

## 📁 Folder Structure

```
leetcode/
├── easy/          # Easy difficulty problems (1-2 difficulty rating)
├── medium/        # Medium difficulty problems (3-4 difficulty rating)
└── hard/          # Hard difficulty problems (5+ difficulty rating)
```

---

## 🧭 Navigation

### By Difficulty
- [Easy Problems](easy/) - Fundamental DSA problems suitable for beginners
- [Medium Problems](medium/) - Intermediate level problems requiring optimization
- [Hard Problems](hard/) - Advanced problems with complex algorithms

---

## 📋 File Naming Convention

Files are named using the LeetCode problem slug/identifier:

**Format:** `{problem-slug}.{ext}`

**Examples:**
- `two-sum.cpp` / `two-sum.py`
- `longest-substring-without-repeating-characters.cpp`
- `merge-intervals.cpp`

Each problem solution file contains:
- Problem description (as comment header)
- Algorithm approach
- Time and space complexity analysis
- Solution code

---

## 🎯 Problem Categories

Problems in this repository cover:

- **Arrays & Strings** - Two pointers, sliding window, prefix sums
- **Linked Lists** - Reversal, cycle detection, merging
- **Trees & Graphs** - Traversals, BST, LCA, shortest paths
- **Dynamic Programming** - 1D/2D DP, knapsack, LIS, LCS
- **Greedy Algorithms** - Activity selection, interval scheduling
- **Backtracking** - Permutations, combinations, N-Queens
- **Binary Search** - Search space reduction, binary search on answer
- **Heaps** - Priority queues, K-th largest/smallest
- **Bit Manipulation** - XOR tricks, bit masks
- **Math & Geometry** - Prime numbers, GCD, coordinate geometry

---

## 🚀 Usage

### Running Solutions

**C++:**
```bash
g++ -std=c++17 {problem-name}.cpp -o solution
./solution
```

**Python:**
```bash
python {problem-name}.py
```

### Organizing Problems

To automatically sort problems by difficulty, run:
```bash
python scripts/sort_leetcode_by_difficulty.py
```

This script uses the LeetCode CLI to fetch difficulty levels and organizes files accordingly.

---

## 📚 Related Resources

- [Algorithm Notes](../notes/) - Comprehensive notes on DSA topics
- [Codeforces Solutions](../codeforces/) - Competitive programming contest problems
- [GeeksforGeeks Solutions](../geeksforgeeks/) - Interview-focused problems
- [Main README](../README.md) - Repository overview

---

## 🔗 External Links

- [LeetCode Platform](https://leetcode.com/)
- [LeetCode Discuss](https://leetcode.com/discuss/)
- [LeetCode Solutions](https://leetcode.com/problemset/)

---

## 📝 Notes

- Solutions are verified and accepted on LeetCode
- All code follows clean code principles
- Complexity analysis is included for each solution
- Solutions are optimized for both time and space when possible

---

_Last updated: Auto-synced daily via GitHub Actions_


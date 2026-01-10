# Backtracking

## Introduction

Backtracking is a systematic method for solving problems by trying partial solutions and abandoning them (backtracking) if they cannot lead to a complete solution.

**Key Concept:** Build solution incrementally and abandon ("backtrack") when it cannot lead to a valid solution.

**When to Use Backtracking:**
- Generate all possible solutions (permutations, combinations)
- Constraint satisfaction problems (N-Queens, Sudoku)
- Path finding with constraints
- Subset generation
- When we need to explore all possibilities

**Time Complexity:** Often exponential, but can be optimized with pruning

---

## Backtracking Template

### Standard Template

#### C++ Template
```cpp
#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& currentSolution, 
               vector<vector<int>>& result,
               /* other parameters */) {
    // Base case: Check if current solution is complete
    if (isSolution(currentSolution)) {
        result.push_back(currentSolution);
        return;
    }
    
    // Generate candidates for next step
    vector<int> candidates = generateCandidates(currentSolution);
    
    for (int candidate : candidates) {
        // Try candidate
        currentSolution.push_back(candidate);
        
        // Check if this choice could lead to solution (pruning)
        if (isValid(currentSolution)) {
            backtrack(currentSolution, result, /* parameters */);
        }
        
        // Backtrack: remove candidate
        currentSolution.pop_back();
    }
}
```

#### Python Template
```python
def backtrack(current_solution, result, **kwargs):
    # Base case: Check if current solution is complete
    if is_solution(current_solution):
        result.append(current_solution[:])  # Copy solution
        return
    
    # Generate candidates for next step
    candidates = generate_candidates(current_solution, **kwargs)
    
    for candidate in candidates:
        # Try candidate
        current_solution.append(candidate)
        
        # Check if this choice could lead to solution (pruning)
        if is_valid(current_solution, **kwargs):
            backtrack(current_solution, result, **kwargs)
        
        # Backtrack: remove candidate
        current_solution.pop()
```

---

## Permutations

### Generate All Permutations

#### C++ Implementation
```cpp
void permute(vector<int>& nums, vector<int>& current, 
             vector<bool>& used, vector<vector<int>>& result) {
    // Base case
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            // Try this number
            used[i] = true;
            current.push_back(nums[i]);
            
            permute(nums, current, used, result);
            
            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    permute(nums, current, used, result);
    return result;
}
```

#### Python Implementation
```python
def permute(nums):
    def backtrack(current, used):
        if len(current) == len(nums):
            result.append(current[:])
            return
        
        for i in range(len(nums)):
            if not used[i]:
                used[i] = True
                current.append(nums[i])
                backtrack(current, used)
                current.pop()
                used[i] = False
    
    result = []
    backtrack([], [False] * len(nums))
    return result
```

### Permutations with Duplicates

#### C++ Implementation
```cpp
void permuteUnique(vector<int>& nums, vector<int>& current,
                   vector<bool>& used, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        // Skip if used or duplicate handled
        if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
            continue;
        }
        
        used[i] = true;
        current.push_back(nums[i]);
        permuteUnique(nums, current, used, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    permuteUnique(nums, current, used, result);
    return result;
}
```

---

## Combinations

### Generate Combinations

#### C++ Implementation
```cpp
void combine(int n, int k, int start, vector<int>& current,
             vector<vector<int>>& result) {
    // Base case: k elements selected
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Try numbers from start to n
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        combine(n, k, i + 1, current, result);  // Next start is i+1
        current.pop_back();  // Backtrack
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    combine(n, k, 1, current, result);
    return result;
}
```

### Combination Sum

#### C++ Implementation
```cpp
void combinationSum(vector<int>& candidates, int target, int start,
                    vector<int>& current, vector<vector<int>>& result) {
    // Base case: target reached
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    // Base case: target exceeded or no more candidates
    if (target < 0 || start >= candidates.size()) {
        return;
    }
    
    // Try including current candidate
    current.push_back(candidates[start]);
    combinationSum(candidates, target - candidates[start], 
                   start, current, result);  // Can reuse same candidate
    current.pop_back();
    
    // Try without current candidate (move to next)
    combinationSum(candidates, target, start + 1, current, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    combinationSum(candidates, target, 0, current, result);
    return result;
}
```

---

## N-Queens Problem

Place N queens on N×N chessboard such that no two queens attack each other.

#### C++ Implementation
```cpp
bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    
    // Check diagonal: top-left to bottom-right
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    // Check diagonal: top-right to bottom-left
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void solveNQueens(int n, int row, vector<string>& board,
                  vector<vector<string>>& result) {
    // Base case: all queens placed
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            solveNQueens(n, row + 1, board, result);
            board[row][col] = '.';  // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solveNQueens(n, 0, board, result);
    return result;
}
```

---

## Sudoku Solver

#### C++ Implementation
```cpp
bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == num) return false;
    }
    
    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) return false;
    }
    
    // Check 3x3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) return false;
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        
                        if (solveSudoku(board)) {
                            return true;
                        }
                        
                        board[i][j] = '.';  // Backtrack
                    }
                }
                return false;  // No valid number found
            }
        }
    }
    return true;  // All cells filled
}
```

---

## Word Search

Find if word exists in 2D grid.

#### C++ Implementation
```cpp
bool dfs(vector<vector<char>>& board, string& word, 
         int i, int j, int index) {
    // Word found
    if (index == word.length()) return true;
    
    // Out of bounds or doesn't match
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[index]) {
        return false;
    }
    
    // Mark as visited
    char temp = board[i][j];
    board[i][j] = '#';
    
    // Try all 4 directions
    bool found = dfs(board, word, i + 1, j, index + 1) ||
                 dfs(board, word, i - 1, j, index + 1) ||
                 dfs(board, word, i, j + 1, index + 1) ||
                 dfs(board, word, i, j - 1, index + 1);
    
    // Backtrack: restore original value
    board[i][j] = temp;
    
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}
```

---

## Subset Generation

### Generate All Subsets

#### C++ Implementation
```cpp
void subsets(vector<int>& nums, int index, vector<int>& current,
             vector<vector<int>>& result) {
    // Add current subset (including empty subset)
    result.push_back(current);
    
    // Try including each remaining element
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        subsets(nums, i + 1, current, result);
        current.pop_back();  // Backtrack
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    subsets(nums, 0, current, result);
    return result;
}
```

### Subsets with Duplicates

#### C++ Implementation
```cpp
void subsetsWithDup(vector<int>& nums, int index, vector<int>& current,
                    vector<vector<int>>& result) {
    result.push_back(current);
    
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates
        if (i > index && nums[i] == nums[i-1]) continue;
        
        current.push_back(nums[i]);
        subsetsWithDup(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    subsetsWithDup(nums, 0, current, result);
    return result;
}
```

---

## Pruning Techniques

### Early Termination
Stop exploring when we know the branch cannot lead to a solution.

### Constraint Propagation
Use constraints to eliminate invalid choices early.

### Memoization
Cache results to avoid recomputing same subproblems.

---

## Complexity Analysis

### Time Complexity
- **Permutations:** O(n! × n)
- **Combinations:** O(2^n) for subsets, O(C(n,k) × k) for combinations
- **N-Queens:** O(n!)
- **Sudoku:** O(9^m) where m is empty cells
- **Word Search:** O(m × n × 4^L) where L is word length

### Space Complexity
- Usually O(n) for recursion stack
- O(n) for current solution
- O(result size) for storing results

---

## Quick Reference

### Backtracking Steps
1. **Choose:** Make a choice
2. **Explore:** Recursively solve with that choice
3. **Unchoose:** Backtrack (undo the choice)
4. **Base Case:** Check if solution is complete

### Pruning Strategies
- **Constraint Checking:** Validate before recursive call
- **Bounds:** Check if remaining choices can complete solution
- **Memoization:** Cache computed states
- **Heuristics:** Order choices to find solution faster

### Common Patterns
- **Generate all solutions** → Backtracking
- **Constraint satisfaction** → Backtracking with validation
- **Path finding** → DFS with backtracking
- **Subset/Permutation** → Backtracking template

---

## Practice Problems

### Easy
- Subsets
- Letter Combinations of Phone Number
- Combination Sum

### Medium
- Permutations
- Permutations II
- Combinations
- N-Queens
- Word Search
- Generate Parentheses

### Hard
- Sudoku Solver
- N-Queens II
- Word Search II
- Restore IP Addresses
- Palindrome Partitioning

---

## External Resources

- [GeeksforGeeks Backtracking](https://www.geeksforgeeks.org/backtracking-algorithms/)
- [LeetCode Backtracking Explore](https://leetcode.com/tag/backtracking/)
- [CP Algorithms Backtracking](https://cp-algorithms.com/combinatorics/backtracking.html)

---

_Last updated: January 2026_


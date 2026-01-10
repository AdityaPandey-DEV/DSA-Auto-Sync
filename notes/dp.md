# Dynamic Programming (DP)

## Introduction

Dynamic Programming is an optimization technique that solves complex problems by breaking them down into simpler subproblems. It stores the results of subproblems to avoid redundant computations, making it more efficient than naive recursion.

**When to Use DP:**
- Optimization problems (maximize/minimize)
- Problems with overlapping subproblems
- Problems with optimal substructure
- Problems that can be broken into similar subproblems

---

## Core Concepts

### 1. Overlapping Subproblems
The same subproblems are solved multiple times in recursion. DP stores results to avoid recomputation.

### 2. Optimal Substructure
An optimal solution contains optimal solutions to subproblems.

### 3. Memoization (Top-Down)
Stores results of recursive calls in a lookup table.

### 4. Tabulation (Bottom-Up)
Builds a table from base cases upward.

---

## Types of DP Problems

### 1. 1D DP
Problems that require a 1-dimensional array for state.

**Examples:**
- Fibonacci numbers
- Climbing stairs
- House robber
- Coin change

### 2. 2D DP
Problems that require a 2-dimensional array for state.

**Examples:**
- Longest Common Subsequence (LCS)
- Edit distance
- Unique paths
- Knapsack (0/1 and fractional)

### 3. DP on Trees
Dynamic programming applied to tree structures.

**Examples:**
- Maximum path sum
- Tree diameter
- Binary tree maximum path sum

### 4. DP with Bitmasks
Using bit manipulation to represent states.

**Examples:**
- Traveling Salesman Problem (TSP)
- Assignment problems

---

## Template Code

### C++ Templates

#### 1D DP Template (Memoization)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Memoization approach
vector<int> memo;

int solve(int n) {
    // Base cases
    if (n <= 1) return n;
    
    // Check if already computed
    if (memo[n] != -1) return memo[n];
    
    // Compute and store
    memo[n] = solve(n-1) + solve(n-2);
    return memo[n];
}

int main() {
    int n = 10;
    memo.assign(n + 1, -1);
    cout << solve(n) << endl;
    return 0;
}
```

#### 1D DP Template (Tabulation)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Tabulation approach
int solve(int n) {
    vector<int> dp(n + 1);
    
    // Base cases
    dp[0] = 0;
    dp[1] = 1;
    
    // Fill table bottom-up
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

#### 2D DP Template
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Base cases
    dp[0][0] = 1;
    for (int i = 1; i < m; i++) dp[i][0] = 1;
    for (int j = 1; j < n; j++) dp[0][j] = 1;
    
    // Fill table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}
```

#### 0/1 Knapsack Template
```cpp
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            // Don't take current item
            dp[i][w] = dp[i-1][w];
            
            // Take current item if possible
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], 
                               values[i-1] + dp[i-1][w - weights[i-1]]);
            }
        }
    }
    
    return dp[n][capacity];
}
```

#### Longest Common Subsequence (LCS)
```cpp
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

#### Longest Increasing Subsequence (LIS)
```cpp
#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

// O(n log n) optimized version using binary search
int lisOptimized(vector<int>& nums) {
    vector<int> tail;
    
    for (int num : nums) {
        auto it = lower_bound(tail.begin(), tail.end(), num);
        if (it == tail.end()) {
            tail.push_back(num);
        } else {
            *it = num;
        }
    }
    
    return tail.size();
}
```

### Python Templates

#### 1D DP Template (Memoization)
```python
from functools import lru_cache

# Using memoization decorator
@lru_cache(maxsize=None)
def solve(n):
    # Base cases
    if n <= 1:
        return n
    
    # Recursive case
    return solve(n-1) + solve(n-2)

# Manual memoization
def solve_memo(n, memo=None):
    if memo is None:
        memo = {}
    
    if n <= 1:
        return n
    
    if n in memo:
        return memo[n]
    
    memo[n] = solve_memo(n-1, memo) + solve_memo(n-2, memo)
    return memo[n]
```

#### 1D DP Template (Tabulation)
```python
def solve(n):
    # Base cases
    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    
    # Fill table bottom-up
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]
```

#### 2D DP Template
```python
def solve(m, n):
    dp = [[0] * n for _ in range(m)]
    
    # Base cases
    dp[0][0] = 1
    for i in range(1, m):
        dp[i][0] = 1
    for j in range(1, n):
        dp[0][j] = 1
    
    # Fill table
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
    return dp[m-1][n-1]
```

#### 0/1 Knapsack Template
```python
def knapsack(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            # Don't take current item
            dp[i][w] = dp[i-1][w]
            
            # Take current item if possible
            if weights[i-1] <= w:
                dp[i][w] = max(dp[i][w], 
                               values[i-1] + dp[i-1][w - weights[i-1]])
    
    return dp[n][capacity]
```

#### Longest Common Subsequence (LCS)
```python
def lcs(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]
```

#### Longest Increasing Subsequence (LIS)
```python
def lis(nums):
    n = len(nums)
    dp = [1] * n
    
    for i in range(1, n):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    return max(dp)

# O(n log n) optimized version
import bisect

def lis_optimized(nums):
    tail = []
    
    for num in nums:
        pos = bisect.bisect_left(tail, num)
        if pos == len(tail):
            tail.append(num)
        else:
            tail[pos] = num
    
    return len(tail)
```

---

## Common Patterns

### Pattern 1: Fibonacci Pattern
Problems that build on previous states:
- Climbing stairs
- Decode ways
- Unique paths

### Pattern 2: Subsequence Problems
Finding longest/shortest subsequences:
- Longest Common Subsequence
- Longest Increasing Subsequence
- Maximum sum increasing subsequence

### Pattern 3: Subset/Partition Problems
Problems involving subsets:
- Subset sum
- Partition equal subset sum
- Target sum

### Pattern 4: String DP
DP on strings:
- Edit distance
- Palindrome partitioning
- Interleaving strings

### Pattern 5: Interval DP
DP on intervals:
- Matrix chain multiplication
- Burst balloons
- Palindrome partitioning

---

## Problem Examples

### Example 1: Climbing Stairs
**Problem:** You can climb 1 or 2 steps at a time. How many ways to reach step n?

```cpp
// C++
int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
```

```python
# Python
def climbStairs(n):
    if n <= 2:
        return n
    prev2, prev1 = 1, 2
    for i in range(3, n + 1):
        current = prev1 + prev2
        prev2, prev1 = prev1, current
    return prev1
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

### Example 2: House Robber
**Problem:** Maximum money that can be robbed without robbing adjacent houses.

```cpp
// C++
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}
```

```python
# Python
def rob(nums):
    n = len(nums)
    if n == 0:
        return 0
    if n == 1:
        return nums[0]
    
    prev2 = nums[0]
    prev1 = max(nums[0], nums[1])
    
    for i in range(2, n):
        current = max(prev1, prev2 + nums[i])
        prev2, prev1 = prev1, current
    
    return prev1
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

### Example 3: Coin Change
**Problem:** Minimum number of coins to make amount.

```cpp
// C++
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}
```

```python
# Python
def coinChange(coins, amount):
    dp = [amount + 1] * (amount + 1)
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] <= amount else -1
```

**Time Complexity:** O(amount × coins)  
**Space Complexity:** O(amount)

---

## Complexity Analysis

### Time Complexity
- **1D DP:** Usually O(n) or O(n²) where n is problem size
- **2D DP:** Usually O(m × n) where m and n are dimensions
- **Knapsack:** O(n × capacity)
- **LCS/LIS:** O(m × n) or O(n log n) with optimization

### Space Complexity
- **Memoization:** O(n) stack space + O(n) memo table
- **Tabulation:** O(n) or O(m × n) for table
- **Space-optimized:** Can often reduce to O(1) for 1D or O(min(m,n)) for 2D

---

## Quick Reference

### DP Problem Identification Checklist
- [ ] Optimization problem (max/min)
- [ ] Can be broken into subproblems
- [ ] Subproblems overlap
- [ ] Has optimal substructure

### DP Approach Steps
1. **Identify state** - What defines a subproblem?
2. **Define transition** - How to compute current state from previous?
3. **Base cases** - Smallest subproblems
4. **Memoization/Tabulation** - Store results
5. **Optimize space** - If possible

### Common DP Optimizations
- **Space optimization:** Use only needed previous states
- **Binary search:** For LIS-type problems
- **Bitmasking:** For small state spaces
- **Sliding window:** For contiguous subarray problems

---

## Practice Problems

### Easy
- Climbing Stairs
- Fibonacci Number
- House Robber
- Best Time to Buy and Sell Stock

### Medium
- Coin Change
- Longest Increasing Subsequence
- Edit Distance
- Unique Paths
- 0/1 Knapsack

### Hard
- Longest Common Subsequence
- Edit Distance (optimized)
- Burst Balloons
- Maximum Path Sum in Binary Tree
- Palindrome Partitioning II

---

## External Resources

- [GeeksforGeeks DP Tutorial](https://www.geeksforgeeks.org/dynamic-programming/)
- [LeetCode DP Explore](https://leetcode.com/tag/dynamic-programming/)
- [CP Algorithms DP](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)

---

_Last updated: January 2026_


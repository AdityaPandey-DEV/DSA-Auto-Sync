# Sliding Window

## Introduction

The sliding window technique is used to efficiently solve problems involving contiguous subarrays or substrings. It maintains a window of elements that slides through the array/string.

**Key Concept:** Maintain a window (subarray/substring) and efficiently update it by sliding.

**Types:**
- **Fixed Window:** Window size is constant
- **Variable Window:** Window size changes based on conditions

**When to Use:**
- Subarray/substring problems
- Problems with contiguous elements
- Finding min/max/longest/shortest subarray
- Frequency counting problems
- Problems with "at most K" or "exactly K" constraints

**Time Complexity:** Usually O(n) - much better than nested loops O(n²)

---

## Fixed Window Size

### Template for Fixed Window

#### C++ Template
```cpp
#include <bits/stdc++.h>
using namespace std;

// Fixed window size k
int fixedWindow(vector<int>& nums, int k) {
    // Calculate sum of first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int maxSum = windowSum;
    
    // Slide window: remove leftmost, add rightmost
    for (int i = k; i < nums.size(); i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

#### Python Template
```python
def fixed_window(nums, k):
    # Calculate sum of first window
    window_sum = sum(nums[:k])
    max_sum = window_sum
    
    # Slide window
    for i in range(k, len(nums)):
        window_sum = window_sum - nums[i - k] + nums[i]
        max_sum = max(max_sum, window_sum)
    
    return max_sum
```

### Maximum Sum of Subarray of Size K

#### C++ Implementation
```cpp
int maxSumSubarray(vector<int>& nums, int k) {
    int windowSum = 0;
    
    // Calculate first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int maxSum = windowSum;
    
    // Slide window
    for (int i = k; i < nums.size(); i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

---

## Variable Window Size

### Template for Variable Window

#### C++ Template
```cpp
int variableWindow(vector<int>& nums, int target) {
    int left = 0;
    int windowSum = 0;
    int minLen = INT_MAX;
    
    for (int right = 0; right < nums.size(); right++) {
        // Expand window
        windowSum += nums[right];
        
        // Shrink window until condition is met
        while (windowSum >= target) {
            minLen = min(minLen, right - left + 1);
            windowSum -= nums[left];
            left++;
        }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}
```

#### Python Template
```python
def variable_window(nums, target):
    left = 0
    window_sum = 0
    min_len = float('inf')
    
    for right in range(len(nums)):
        # Expand window
        window_sum += nums[right]
        
        # Shrink window until condition is met
        while window_sum >= target:
            min_len = min(min_len, right - left + 1)
            window_sum -= nums[left]
            left += 1
    
    return min_len if min_len != float('inf') else 0
```

### Minimum Size Subarray Sum

#### C++ Implementation
```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}
```

---

## Longest Substring with K Distinct Characters

#### C++ Implementation
```cpp
int longestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;
        
        // Shrink window if more than k distinct characters
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

### Longest Substring Without Repeating Characters

#### C++ Implementation
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        // If character already in window, move left pointer
        if (charIndex.find(s[right]) != charIndex.end() && 
            charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        
        charIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

#### Python Implementation
```python
def length_of_longest_substring(s):
    char_index = {}
    left = 0
    max_len = 0
    
    for right in range(len(s)):
        if s[right] in char_index and char_index[s[right]] >= left:
            left = char_index[s[right]] + 1
        
        char_index[s[right]] = right
        max_len = max(max_len, right - left + 1)
    
    return max_len
```

---

## Sliding Window Maximum

### Using Deque

#### C++ Implementation
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove indices outside window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove indices with smaller values
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Window is complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}
```

#### Python Implementation
```python
from collections import deque

def max_sliding_window(nums, k):
    dq = deque()  # Store indices
    result = []
    
    for i in range(len(nums)):
        # Remove indices outside window
        while dq and dq[0] <= i - k:
            dq.popleft()
        
        # Remove indices with smaller values
        while dq and nums[dq[-1]] <= nums[i]:
            dq.pop()
        
        dq.append(i)
        
        # Window is complete
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result
```

---

## Minimum Window Substring

Find minimum window in string that contains all characters of another string.

#### C++ Implementation
```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    
    // Count characters needed
    for (char ch : t) {
        need[ch]++;
    }
    
    int left = 0, right = 0;
    int valid = 0;  // Number of characters with satisfied frequency
    int start = 0, minLen = INT_MAX;
    
    while (right < s.length()) {
        char ch = s[right];
        right++;
        
        // Update window
        if (need.count(ch)) {
            window[ch]++;
            if (window[ch] == need[ch]) {
                valid++;
            }
        }
        
        // Shrink window
        while (valid == need.size()) {
            // Update result
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            
            char d = s[left];
            left++;
            
            // Update window
            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

---

## Count Substrings with Exactly K Distinct Characters

#### C++ Implementation
```cpp
int countSubstringsKDistinct(string s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int atMostKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0;
    int count = 0;
    
    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;
        
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }
        
        // All substrings ending at right with at most k distinct
        count += right - left + 1;
    }
    
    return count;
}
```

---

## Fruits into Baskets (At Most 2 Types)

#### C++ Implementation
```cpp
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int left = 0;
    int maxFruits = 0;
    
    for (int right = 0; right < fruits.size(); right++) {
        basket[fruits[right]]++;
        
        // At most 2 types
        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }
        
        maxFruits = max(maxFruits, right - left + 1);
    }
    
    return maxFruits;
}
```

---

## Complexity Analysis

### Time Complexity
- **Fixed Window:** O(n) - single pass
- **Variable Window:** O(n) - each element visited at most twice (once by left, once by right)
- **Sliding Window Maximum:** O(n) using deque
- **Minimum Window Substring:** O(|s| + |t|)

### Space Complexity
- **Fixed Window:** O(1) - just variables
- **Variable Window:** O(k) for hash map (k is distinct characters)
- **Sliding Window Maximum:** O(k) for deque

---

## Quick Reference

### When to Use Sliding Window
- [ ] Contiguous subarray/substring
- [ ] Fixed or variable window size
- [ ] "At most K", "Exactly K", "At least K" constraints
- [ ] Frequency counting problems
- [ ] Min/max/longest/shortest subarray

### Common Patterns
1. **Fixed window** → Pre-calculate first window, then slide
2. **Variable window** → Expand with right, shrink with left
3. **Frequency map** → Use hash map to track character/element counts
4. **Deque for max/min** → Use deque for sliding window maximum/minimum

### Template Selection
- **Fixed size K** → Calculate first window, slide with subtraction/addition
- **Variable size** → Two pointers (left, right), expand and shrink
- **Sliding maximum** → Deque to maintain maximum
- **Character frequency** → Hash map to track frequencies

---

## Practice Problems

### Easy
- Maximum Average Subarray I
- Best Time to Buy and Sell Stock
- Contains Duplicate II

### Medium
- Longest Substring Without Repeating Characters
- Minimum Size Subarray Sum
- Fruit Into Baskets
- Longest Repeating Character Replacement
- Permutation in String

### Hard
- Sliding Window Maximum
- Minimum Window Substring
- Substring with Concatenation of All Words
- Longest Substring with At Most K Distinct Characters

---

## External Resources

- [GeeksforGeeks Sliding Window](https://www.geeksforgeeks.org/window-sliding-technique/)
- [LeetCode Sliding Window Explore](https://leetcode.com/tag/sliding-window/)
- [CP Algorithms Two Pointers](https://cp-algorithms.com/sequences/two_pointers.html)

---

_Last updated: January 2026_


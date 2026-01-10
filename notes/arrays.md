# Array Techniques

## Introduction

Arrays are fundamental data structures in competitive programming. This guide covers essential techniques for solving array problems efficiently.

**Key Techniques:**
- Two Pointers
- Sliding Window
- Prefix Sums
- Difference Arrays
- Kadane's Algorithm
- Subarray Problems
- Array Rotation and Manipulation

---

## Two Pointers Technique

Use two pointers moving towards each other or in the same direction to solve problems efficiently.

### Template

#### C++ Template
```cpp
#include <bits/stdc++.h>
using namespace std;

// Two pointers moving towards each other
void twoPointers(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        // Process elements at left and right
        if (condition) {
            left++;
        } else {
            right--;
        }
    }
}

// Two pointers moving in same direction
void twoPointersSame(vector<int>& nums) {
    int slow = 0, fast = 0;
    
    while (fast < nums.size()) {
        if (condition) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
}
```

#### Python Template
```python
def two_pointers(nums):
    left, right = 0, len(nums) - 1
    
    while left < right:
        # Process elements at left and right
        if condition:
            left += 1
        else:
            right -= 1

def two_pointers_same(nums):
    slow = fast = 0
    
    while fast < len(nums):
        if condition:
            nums[slow] = nums[fast]
            slow += 1
        fast += 1
```

### Example: Two Sum (Sorted Array)
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}
```

---

## Sliding Window Technique

Use a window of fixed or variable size that slides through the array.

### Fixed Window Size

#### C++ Implementation
```cpp
int maxSumFixedWindow(vector<int>& nums, int k) {
    int windowSum = 0;
    
    // Calculate sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int maxSum = windowSum;
    
    // Slide the window
    for (int i = k; i < nums.size(); i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

### Variable Window Size

#### C++ Implementation
```cpp
int minSubarrayLen(vector<int>& nums, int target) {
    int left = 0, sum = 0;
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

## Prefix Sums

Calculate cumulative sum to answer range sum queries efficiently.

#### C++ Implementation
```cpp
class PrefixSum {
    vector<int> prefix;
public:
    PrefixSum(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        prefix[0] = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    // Sum from index i to j (inclusive)
    int rangeSum(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
};
```

#### Python Implementation
```python
class PrefixSum:
    def __init__(self, nums):
        self.prefix = [0] * (len(nums) + 1)
        
        for i in range(len(nums)):
            self.prefix[i + 1] = self.prefix[i] + nums[i]
    
    def range_sum(self, i, j):
        return self.prefix[j + 1] - self.prefix[i]
```

---

## Difference Arrays

Efficiently handle range updates (add value to all elements in range).

#### C++ Implementation
```cpp
void rangeUpdate(vector<int>& diff, int l, int r, int val) {
    diff[l] += val;
    if (r + 1 < diff.size()) {
        diff[r + 1] -= val;
    }
}

vector<int> buildArray(vector<int>& diff) {
    vector<int> result(diff.size());
    result[0] = diff[0];
    
    for (int i = 1; i < diff.size(); i++) {
        result[i] = result[i - 1] + diff[i];
    }
    
    return result;
}
```

---

## Kadane's Algorithm

Find maximum sum subarray in O(n) time.

#### C++ Implementation
```cpp
int maxSubarraySum(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

// With indices tracking
pair<int, int> maxSubarraySumWithIndices(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0, end = 0, tempStart = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        if (currentSum < 0) {
            currentSum = nums[i];
            tempStart = i;
        } else {
            currentSum += nums[i];
        }
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }
    
    return {start, end};
}
```

#### Python Implementation
```python
def max_subarray_sum(nums):
    max_sum = current_sum = nums[0]
    
    for i in range(1, len(nums)):
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)
    
    return max_sum
```

---

## Array Rotation

### Left Rotation

#### C++ Implementation
```cpp
void rotateLeft(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}

// Using extra space
vector<int> rotateLeftExtra(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> result(n);
    
    for (int i = 0; i < n; i++) {
        result[(i - k + n) % n] = nums[i];
    }
    
    return result;
}
```

### Right Rotation

#### C++ Implementation
```cpp
void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}
```

---

## Subarray Problems

### Count Subarrays with Given Sum

#### C++ Implementation (Using HashMap)
```cpp
int subarraySum(vector<int>& nums, int target) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    
    int count = 0, sum = 0;
    
    for (int num : nums) {
        sum += num;
        if (prefixSumCount.find(sum - target) != prefixSumCount.end()) {
            count += prefixSumCount[sum - target];
        }
        prefixSumCount[sum]++;
    }
    
    return count;
}
```

### Longest Subarray with K Distinct Elements

#### C++ Implementation
```cpp
int longestSubarrayKDistinct(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;
        
        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

---

## Array Manipulation

### Merge Intervals

#### C++ Implementation
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    
    return merged;
}
```

### Next Greater Element

#### C++ Implementation (Using Stack)
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    return result;
}
```

### Product of Array Except Self

#### C++ Implementation
```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    // Left product
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Right product
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}
```

---

## Complexity Analysis

### Time Complexity
- **Two Pointers:** O(n)
- **Sliding Window:** O(n)
- **Prefix Sum:** O(n) construction, O(1) query
- **Kadane's Algorithm:** O(n)
- **Array Rotation:** O(n)
- **Subarray Problems:** O(n) to O(n²)

### Space Complexity
- **Two Pointers:** O(1)
- **Sliding Window:** O(1) to O(k) for window
- **Prefix Sum:** O(n)
- **Kadane's Algorithm:** O(1)
- **Most techniques:** O(1) to O(n)

---

## Quick Reference

### Technique Selection Guide
- **Two elements sum/product** → Two Pointers
- **Contiguous subarray** → Sliding Window or Kadane
- **Range sum queries** → Prefix Sum
- **Range updates** → Difference Array
- **Maximum subarray** → Kadane's Algorithm
- **Array rotation** → Reversal technique
- **Next/Previous greater/smaller** → Stack

### Common Patterns
1. **Two Sum variants** → Hash map or two pointers
2. **Subarray problems** → Sliding window or prefix sum
3. **Rotation problems** → Reversal or modular arithmetic
4. **Interval problems** → Sorting + merging

---

## Practice Problems

### Easy
- Two Sum
- Best Time to Buy and Sell Stock
- Maximum Subarray (Kadane's)
- Move Zeroes (Two Pointers)

### Medium
- 3Sum
- Container With Most Water
- Subarray Sum Equals K
- Longest Substring Without Repeating Characters
- Product of Array Except Self

### Hard
- Trapping Rain Water
- Sliding Window Maximum
- Maximum Sum Rectangle in 2D Matrix
- Merge Intervals
- First Missing Positive

---

## External Resources

- [LeetCode Array Explore](https://leetcode.com/tag/array/)
- [GeeksforGeeks Array Tutorial](https://www.geeksforgeeks.org/array-data-structure/)
- [CP Algorithms Prefix Sums](https://cp-algorithms.com/sequences/prefix_sum.html)

---

_Last updated: January 2026_


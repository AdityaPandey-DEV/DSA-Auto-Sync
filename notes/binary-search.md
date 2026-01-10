# Binary Search

## Introduction

Binary Search is an efficient searching algorithm that works on sorted arrays/lists. It repeatedly divides the search space in half, eliminating half of the remaining elements in each iteration.

**Key Principle:** Compare target with middle element, eliminate half based on comparison.

**When to Use Binary Search:**
- Sorted array/list
- Search space that can be reduced by half
- Optimization problems (find minimum/maximum satisfying condition)
- Binary search on answer (for problems without explicit array)

**Time Complexity:** O(log n)  
**Space Complexity:** O(1) iterative, O(log n) recursive

---

## Core Concepts

### Prerequisites
1. **Sorted Data Structure** - Array/list must be sorted
2. **Searchable Space** - Can eliminate half of space based on condition
3. **Monotonic Property** - Condition must be monotonic (either increasing or decreasing)

### Types of Binary Search
1. **Standard Binary Search** - Find exact element
2. **Binary Search on Answer** - Find optimal value satisfying condition
3. **Lower Bound** - First position where element ≥ target
4. **Upper Bound** - First position where element > target
5. **Rotated Array Search** - Search in rotated sorted array

---

## Standard Binary Search

### Basic Implementation

#### C++ Implementation (Iterative)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Standard binary search - find target
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (nums[mid] == target) {
            return mid;  // Found
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }
    
    return -1;  // Not found
}
```

#### C++ Implementation (Recursive)
```cpp
int binarySearchRecursive(vector<int>& nums, int target, int left, int right) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        return binarySearchRecursive(nums, target, mid + 1, right);
    } else {
        return binarySearchRecursive(nums, target, left, mid - 1);
    }
}

int binarySearch(vector<int>& nums, int target) {
    return binarySearchRecursive(nums, target, 0, nums.size() - 1);
}
```

#### Python Implementation (Iterative)
```python
def binary_search(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2  # Avoid overflow
        
        if nums[mid] == target:
            return mid  # Found
        elif nums[mid] < target:
            left = mid + 1  # Search right half
        else:
            right = mid - 1  # Search left half
    
    return -1  # Not found
```

#### Python Implementation (Recursive)
```python
def binary_search_recursive(nums, target, left, right):
    if left > right:
        return -1
    
    mid = left + (right - left) // 2
    
    if nums[mid] == target:
        return mid
    elif nums[mid] < target:
        return binary_search_recursive(nums, target, mid + 1, right)
    else:
        return binary_search_recursive(nums, target, left, mid - 1)

def binary_search(nums, target):
    return binary_search_recursive(nums, target, 0, len(nums) - 1)
```

---

## Lower Bound and Upper Bound

### Lower Bound (First Position ≥ Target)
Finds the first position where element is greater than or equal to target.

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

// Lower bound - first position where nums[i] >= target
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;  // Keep mid as potential answer
        }
    }
    
    return left;  // First position where nums[i] >= target
}

// Using STL
int lowerBoundSTL(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}
```

#### Python Implementation
```python
def lower_bound(nums, target):
    left, right = 0, len(nums)
    
    while left < right:
        mid = left + (right - left) // 2
        
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid  # Keep mid as potential answer
    
    return left  # First position where nums[i] >= target

# Using bisect module
import bisect

def lower_bound_bisect(nums, target):
    return bisect.bisect_left(nums, target)
```

### Upper Bound (First Position > Target)
Finds the first position where element is strictly greater than target.

#### C++ Implementation
```cpp
// Upper bound - first position where nums[i] > target
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;  // Keep mid as potential answer
        }
    }
    
    return left;  # First position where nums[i] > target
}

// Using STL
int upperBoundSTL(vector<int>& nums, int target) {
    return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
}
```

#### Python Implementation
```python
def upper_bound(nums, target):
    left, right = 0, len(nums)
    
    while left < right:
        mid = left + (right - left) // 2
        
        if nums[mid] <= target:
            left = mid + 1
        else:
            right = mid  # Keep mid as potential answer
    
    return left  # First position where nums[i] > target

# Using bisect module
import bisect

def upper_bound_bisect(nums, target):
    return bisect.bisect_right(nums, target)
```

### Finding Range of Target
Find first and last position of target in sorted array.

#### C++ Implementation
```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    int first = lowerBound(nums, target);
    
    if (first == nums.size() || nums[first] != target) {
        return {-1, -1};
    }
    
    int last = upperBound(nums, target) - 1;
    return {first, last};
}
```

#### Python Implementation
```python
def search_range(nums, target):
    first = lower_bound(nums, target)
    
    if first == len(nums) or nums[first] != target:
        return [-1, -1]
    
    last = upper_bound(nums, target) - 1
    return [first, last]
```

---

## Binary Search on Answer

Used for optimization problems where we search for the optimal value satisfying a condition.

### Template

#### C++ Template
```cpp
// Binary search on answer - find minimum satisfying condition
int binarySearchOnAnswer(vector<int>& nums, int condition) {
    int left = 0, right = nums.back();  // Define search space
    int answer = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isValid(nums, mid, condition)) {
            answer = mid;
            right = mid - 1;  // Try smaller value (for minimum)
            // left = mid + 1;  // For maximum, try larger value
        } else {
            left = mid + 1;  // Search right half
            // right = mid - 1;  // For opposite condition
        }
    }
    
    return answer;
}

// Example: Find minimum value satisfying condition
bool isValid(vector<int>& nums, int value, int condition) {
    // Define your validation logic here
    // Return true if value satisfies condition
    return true;  // Placeholder
}
```

#### Python Template
```python
def binary_search_on_answer(nums, condition):
    left, right = 0, nums[-1] if nums else 0  # Define search space
    answer = -1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if is_valid(nums, mid, condition):
            answer = mid
            right = mid - 1  # Try smaller value (for minimum)
            # left = mid + 1  # For maximum, try larger value
        else:
            left = mid + 1  # Search right half
            # right = mid - 1  # For opposite condition
    
    return answer

def is_valid(nums, value, condition):
    # Define your validation logic here
    # Return True if value satisfies condition
    return True  # Placeholder
```

### Example: Split Array Largest Sum
Find the minimum largest sum when splitting array into k subarrays.

#### C++ Implementation
```cpp
bool canSplit(vector<int>& nums, int k, int maxSum) {
    int subarrays = 1;
    int currentSum = 0;
    
    for (int num : nums) {
        if (currentSum + num > maxSum) {
            subarrays++;
            currentSum = num;
            if (subarrays > k) return false;
        } else {
            currentSum += num;
        }
    }
    
    return true;
}

int splitArray(vector<int>& nums, int k) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);
    int answer = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canSplit(nums, k, mid)) {
            answer = mid;
            right = mid - 1;  // Try smaller sum
        } else {
            left = mid + 1;  // Need larger sum
        }
    }
    
    return answer;
}
```

---

## Rotated Sorted Array Search

Search in a rotated sorted array (array rotated at some pivot).

### Find Pivot in Rotated Array

#### C++ Implementation
```cpp
int findPivot(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;  # Pivot is in right half
        } else {
            right = mid;  # Pivot is in left half or at mid
        }
    }
    
    return left;  # Pivot index
}
```

### Search in Rotated Sorted Array

#### C++ Implementation
```cpp
int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {  // Right half is sorted
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

#### Python Implementation
```python
def search_rotated(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if nums[mid] == target:
            return mid
        
        # Left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:  # Right half is sorted
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    
    return -1
```

---

## Search in 2D Matrix

Search in a matrix where each row and column is sorted.

#### C++ Implementation
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;  // Start from top-right
    
    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--;  // Move left
        } else {
            row++;  // Move down
        }
    }
    
    return false;
}
```

---

## Common Patterns

### Pattern 1: Find Peak Element
Find peak in mountain array.

```cpp
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;  // Peak is in right half
        } else {
            right = mid;  // Peak is in left half or at mid
        }
    }
    
    return left;
}
```

### Pattern 2: Find Minimum in Rotated Array
```cpp
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return nums[left];
}
```

### Pattern 3: Search in Nearly Sorted Array
Array where each element can be at most k positions away from its sorted position.

```cpp
int searchNearlySorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        if (mid > 0 && nums[mid - 1] == target) return mid - 1;
        if (mid < nums.size() - 1 && nums[mid + 1] == target) return mid + 1;
        
        if (nums[mid] < target) {
            left = mid + 2;  // Skip one position
        } else {
            right = mid - 2;  // Skip one position
        }
    }
    
    return -1;
}
```

---

## Complexity Analysis

### Time Complexity
- **Standard Binary Search:** O(log n)
- **Lower/Upper Bound:** O(log n)
- **Rotated Array Search:** O(log n)
- **Binary Search on Answer:** O(log n × f(n)) where f(n) is validation time

### Space Complexity
- **Iterative:** O(1)
- **Recursive:** O(log n) due to recursion stack

---

## Quick Reference

### Binary Search Checklist
- [ ] Data structure is sorted (or can be sorted)
- [ ] Problem can be reduced to yes/no question
- [ ] Search space can be halved based on condition
- [ ] Condition is monotonic

### Common Mistakes
- **Off-by-one errors** - Be careful with boundary conditions
- **Overflow** - Use `left + (right - left) / 2` instead of `(left + right) / 2`
- **Infinite loops** - Ensure boundaries are updated correctly
- **Wrong comparison** - Check whether to use `<`, `<=`, `>`, `>=`

### Template Selection
- **Exact match** → Standard binary search
- **First position** → Lower bound
- **Last position** → Upper bound - 1
- **Range search** → Lower bound + Upper bound
- **Optimization** → Binary search on answer
- **Rotated array** → Modified binary search with pivot detection

---

## Practice Problems

### Easy
- Binary Search (Standard)
- First Bad Version
- Search Insert Position
- Sqrt(x)

### Medium
- Search in Rotated Sorted Array
- Find First and Last Position
- Find Peak Element
- Search in 2D Matrix
- Koko Eating Bananas (Binary search on answer)

### Hard
- Split Array Largest Sum
- Minimum Number of Days to Make m Bouquets
- Capacity To Ship Packages Within D Days
- Kth Smallest Element in Sorted Matrix

---

## External Resources

- [GeeksforGeeks Binary Search](https://www.geeksforgeeks.org/binary-search/)
- [LeetCode Binary Search Explore](https://leetcode.com/tag/binary-search/)
- [CP Algorithms Binary Search](https://cp-algorithms.com/num_methods/binary_search.html)

---

_Last updated: January 2026_


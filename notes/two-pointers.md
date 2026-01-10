# Two Pointers Technique

## Introduction

The two pointers technique uses two pointers that traverse through a data structure (typically an array or string) to solve problems efficiently.

**Key Concept:** Use two pointers moving in the same direction, opposite directions, or at different speeds.

**When to Use:**
- Sorted arrays
- Palindrome checks
- Pair sum problems
- Removing duplicates
- Array manipulation
- String processing
- Linked list problems

**Types:**
- **Opposite Ends:** Pointers start from both ends
- **Same Direction:** Both pointers move in same direction (fast/slow)
- **Different Speeds:** One pointer moves faster than the other

**Time Complexity:** Usually O(n) - linear time

---

## Two Pointers Moving Towards Each Other

### Template

#### C++ Template
```cpp
#include <bits/stdc++.h>
using namespace std;

void twoPointers(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        // Process elements at left and right
        if (condition) {
            left++;
        } else {
            right--;
        }
    }
}
```

#### Python Template
```python
def two_pointers(nums):
    left = 0
    right = len(nums) - 1
    
    while left < right:
        # Process elements at left and right
        if condition:
            left += 1
        else:
            right -= 1
```

### Two Sum (Sorted Array)

#### C++ Implementation
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
    
    return {};  // No solution found
}
```

#### Python Implementation
```python
def two_sum(nums, target):
    left, right = 0, len(nums) - 1
    
    while left < right:
        current_sum = nums[left] + nums[right]
        
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return []  # No solution found
```

### 3Sum

#### C++ Implementation
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    
    for (int i = 0; i < nums.size() - 2; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = nums.size() - 1;
        int target = -nums[i];
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}
```

### Valid Palindrome

#### C++ Implementation
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        
        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
```

#### Python Implementation
```python
def is_palindrome(s):
    left, right = 0, len(s) - 1
    
    while left < right:
        # Skip non-alphanumeric characters
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        
        # Compare characters (case-insensitive)
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True
```

### Container With Most Water

#### C++ Implementation
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        int width = right - left;
        int minHeight = min(height[left], height[right]);
        maxWater = max(maxWater, width * minHeight);
        
        // Move pointer with smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}
```

---

## Two Pointers Moving in Same Direction

### Template (Fast and Slow)

#### C++ Template
```cpp
void twoPointersSame(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    
    while (fast < nums.size()) {
        if (condition) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    
    return slow;  // New length
}
```

#### Python Template
```python
def two_pointers_same(nums):
    slow = fast = 0
    
    while fast < len(nums):
        if condition:
            nums[slow] = nums[fast]
            slow += 1
        fast += 1
    
    return slow  # New length
```

### Remove Duplicates from Sorted Array

#### C++ Implementation
```cpp
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int slow = 1;
    
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    
    return slow;
}
```

### Move Zeroes

#### C++ Implementation
```cpp
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    
    // Move all non-zero elements to front
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    
    // Fill remaining positions with zeros
    while (slow < nums.size()) {
        nums[slow] = 0;
        slow++;
    }
}
```

### Remove Element

#### C++ Implementation
```cpp
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    
    return slow;
}
```

---

## Linked List Two Pointers

### Cycle Detection (Floyd's Algorithm)

#### C++ Implementation
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true;  // Cycle detected
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}
```

### Find Middle of Linked List

#### C++ Implementation
```cpp
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
```

### Remove Nth Node From End

#### C++ Implementation
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    
    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Remove nth node from end
    slow->next = slow->next->next;
    
    return dummy->next;
}
```

---

## Different Speed Pointers

### Intersection of Two Linked Lists

#### C++ Implementation
```cpp
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;
    
    // When one reaches end, switch to other list
    // This makes them meet at intersection (if exists)
    while (ptrA != ptrB) {
        ptrA = (ptrA == nullptr) ? headB : ptrA->next;
        ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    }
    
    return ptrA;
}
```

---

## Array Partitioning

### Partition Array (Quick Select)

#### C++ Implementation
```cpp
int partition(vector<int>& nums, int left, int right, int pivot) {
    int pivotValue = nums[pivot];
    swap(nums[pivot], nums[right]);
    
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivotValue) {
            swap(nums[i], nums[storeIndex]);
            storeIndex++;
        }
    }
    
    swap(nums[storeIndex], nums[right]);
    return storeIndex;
}
```

### Sort Colors (Dutch National Flag)

#### C++ Implementation
```cpp
void sortColors(vector<int>& nums) {
    int left = 0;      // Next position for 0
    int right = nums.size() - 1;  // Next position for 2
    int current = 0;
    
    while (current <= right) {
        if (nums[current] == 0) {
            swap(nums[left], nums[current]);
            left++;
            current++;
        } else if (nums[current] == 2) {
            swap(nums[right], nums[current]);
            right--;
            // Don't increment current, check swapped element
        } else {
            current++;
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity
- **Two Sum:** O(n)
- **3Sum:** O(n²)
- **Palindrome Check:** O(n)
- **Remove Duplicates:** O(n)
- **Cycle Detection:** O(n)
- **Linked List Operations:** O(n)

### Space Complexity
- **Most operations:** O(1) - just using pointers
- **Some operations:** O(1) - in-place modifications

---

## Quick Reference

### When to Use Two Pointers
- [ ] Sorted array problems
- [ ] Palindrome checks
- [ ] Pair sum problems
- [ ] Removing duplicates in-place
- [ ] Linked list problems
- [ ] Array partitioning

### Common Patterns
1. **Opposite ends** → Two sum, palindrome, container with water
2. **Same direction** → Remove duplicates, move zeros
3. **Fast/slow** → Cycle detection, find middle
4. **Different speeds** → Intersection, remove nth from end

### Template Selection
- **Sorted array + target** → Opposite ends (left, right)
- **In-place modification** → Same direction (slow, fast)
- **Linked list cycle** → Fast/slow pointers
- **Partitioning** → Multiple pointers

---

## Practice Problems

### Easy
- Two Sum (sorted array)
- Valid Palindrome
- Remove Duplicates from Sorted Array
- Move Zeroes
- Merge Sorted Array

### Medium
- 3Sum
- Container With Most Water
- Trapping Rain Water
- Remove Nth Node From End
- Linked List Cycle II

### Hard
- Trapping Rain Water
- 4Sum
- Merge k Sorted Lists (with two pointers technique)
- Reverse Nodes in k-Group

---

## External Resources

- [GeeksforGeeks Two Pointers](https://www.geeksforgeeks.org/two-pointers-technique/)
- [LeetCode Two Pointers Explore](https://leetcode.com/tag/two-pointers/)
- [CP Algorithms Two Pointers](https://cp-algorithms.com/sequences/two_pointers.html)

---

_Last updated: January 2026_


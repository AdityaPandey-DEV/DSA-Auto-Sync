# Heap / Priority Queue

## Introduction

A heap is a complete binary tree that satisfies the heap property. Heaps are commonly implemented as priority queues.

**Heap Types:**
- **Min Heap:** Parent ≤ children (smallest at root)
- **Max Heap:** Parent ≥ children (largest at root)

**Operations:**
- Insert: O(log n)
- Extract Min/Max: O(log n)
- Get Min/Max: O(1)

**When to Use Heaps:**
- K-th largest/smallest element
- Merge K sorted lists/arrays
- Find median in stream
- Top K frequent elements
- Scheduling problems

---

## Heap Implementation

### Min Heap Implementation (Array-based)

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        
        if (l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }
        
        if (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    
public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    
    int extractMin() {
        if (heap.empty()) return -1;
        
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return min;
    }
    
    int getMin() {
        return heap.empty() ? -1 : heap[0];
    }
    
    bool empty() {
        return heap.empty();
    }
    
    int size() {
        return heap.size();
    }
};
```

### Using STL Priority Queue

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

// Min Heap (STL priority_queue with greater comparator)
priority_queue<int, vector<int>, greater<int>> minHeap;

// Max Heap (default)
priority_queue<int> maxHeap;

// Custom comparator
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // For min heap
    }
};

priority_queue<int, vector<int>, Compare> customHeap;
```

#### Python Implementation
```python
import heapq

# Min Heap (heapq maintains min heap)
heap = []
heapq.heappush(heap, 5)
heapq.heappush(heap, 2)
heapq.heappush(heap, 8)
min_val = heapq.heappop(heap)  # Returns 2

# Max Heap (negate values)
max_heap = []
heapq.heappush(max_heap, -5)
heapq.heappush(max_heap, -2)
max_val = -heapq.heappop(max_heap)  # Returns 5
```

---

## K-th Largest/Smallest Element

### Find K-th Largest Element

#### C++ Implementation
```cpp
// Using min heap of size k
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}
```

#### Python Implementation
```python
import heapq

def find_kth_largest(nums, k):
    min_heap = []
    
    for num in nums:
        heapq.heappush(min_heap, num)
        if len(min_heap) > k:
            heapq.heappop(min_heap)
    
    return min_heap[0]
```

### Find K-th Smallest Element

#### C++ Implementation
```cpp
// Using max heap of size k
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    
    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    return maxHeap.top();
}
```

---

## Merge K Sorted Lists

#### C++ Implementation
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto compare = [](ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min heap
    };
    
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
    
    // Push first node of each list
    for (ListNode* list : lists) {
        if (list) {
            pq.push(list);
        }
    }
    
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        
        current->next = node;
        current = current->next;
        
        if (node->next) {
            pq.push(node->next);
        }
    }
    
    return dummy.next;
}
```

#### Python Implementation
```python
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_k_lists(lists):
    min_heap = []
    
    # Push first node of each list
    for i, node in enumerate(lists):
        if node:
            heapq.heappush(min_heap, (node.val, i, node))
    
    dummy = ListNode(0)
    current = dummy
    
    while min_heap:
        val, idx, node = heapq.heappop(min_heap)
        current.next = node
        current = current.next
        
        if node.next:
            heapq.heappush(min_heap, (node.next.val, idx, node.next))
    
    return dummy.next
```

---

## Top K Frequent Elements

#### C++ Implementation
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    auto compare = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;  // Min heap by frequency
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
    
    for (auto& pair : freq) {
        pq.push({pair.first, pair.second});
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

#### Python Implementation
```python
import heapq
from collections import Counter

def top_k_frequent(nums, k):
    freq = Counter(nums)
    
    min_heap = []
    for num, count in freq.items():
        heapq.heappush(min_heap, (count, num))
        if len(min_heap) > k:
            heapq.heappop(min_heap)
    
    return [num for count, num in min_heap[::-1]]
```

---

## Find Median in Stream

#### C++ Implementation
```cpp
class MedianFinder {
private:
    priority_queue<int> maxHeap;  // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Upper half
    
public:
    void addNum(int num) {
        maxHeap.push(num);
        
        // Balance heaps
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

#### Python Implementation
```python
import heapq

class MedianFinder:
    def __init__(self):
        self.max_heap = []  # Lower half (negated for max heap)
        self.min_heap = []  # Upper half
    
    def add_num(self, num):
        heapq.heappush(self.max_heap, -num)
        
        # Balance heaps
        heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        
        if len(self.max_heap) < len(self.min_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
    
    def find_median(self):
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        return (-self.max_heap[0] + self.min_heap[0]) / 2.0
```

---

## K Closest Points to Origin

#### C++ Implementation
```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto compare = [](vector<int>& a, vector<int>& b) {
        int distA = a[0] * a[0] + a[1] * a[1];
        int distB = b[0] * b[0] + b[1] * b[1];
        return distA < distB;  // Max heap by distance
    };
    
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
    
    for (auto& point : points) {
        pq.push(point);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<vector<int>> result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    
    return result;
}
```

---

## Complexity Analysis

### Time Complexity
- **Insert:** O(log n)
- **Extract Min/Max:** O(log n)
- **Get Min/Max:** O(1)
- **Heapify:** O(n) to build heap from array
- **K-th Largest/Smallest:** O(n log k)
- **Merge K Lists:** O(n log k) where n is total elements, k is number of lists

### Space Complexity
- **Heap Storage:** O(n)
- **K-th Element:** O(k)
- **Merge K Lists:** O(k) for priority queue

---

## Quick Reference

### When to Use Heaps
- [ ] K-th largest/smallest element
- [ ] Top K frequent/smallest/largest
- [ ] Merge K sorted sequences
- [ ] Median finding
- [ ] Scheduling with priorities
- [ ] Event-driven simulation

### Heap vs Sorting
- **Heap:** Better when you need to maintain order dynamically
- **Sorting:** Better when you need all elements sorted once

### STL Usage (C++)
- **Min Heap:** `priority_queue<T, vector<T>, greater<T>>`
- **Max Heap:** `priority_queue<T>` (default)
- **Custom Comparator:** Define function object or lambda

### Python heapq Module
- **Min Heap:** Default behavior
- **Max Heap:** Negate values
- **Heapify:** `heapq.heapify(list)` - O(n)
- **Push:** `heapq.heappush(heap, item)` - O(log n)
- **Pop:** `heapq.heappop(heap)` - O(log n)

---

## Practice Problems

### Easy
- Kth Largest Element in Array
- Last Stone Weight
- K Closest Points to Origin

### Medium
- Merge K Sorted Lists
- Top K Frequent Elements
- Find K Pairs with Smallest Sums
- Meeting Rooms II
- Task Scheduler

### Hard
- Find Median from Data Stream
- Sliding Window Maximum
- The Skyline Problem
- IPO

---

## External Resources

- [GeeksforGeeks Heap Tutorial](https://www.geeksforgeeks.org/heap-data-structure/)
- [LeetCode Heap Explore](https://leetcode.com/tag/heap/)
- [CP Algorithms Binary Heap](https://cp-algorithms.com/data_structures/heap.html)

---

_Last updated: January 2026_


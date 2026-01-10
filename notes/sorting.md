# Sorting Algorithms

## Introduction

Sorting is a fundamental operation in computer science. This guide covers essential sorting algorithms with their implementations and complexity analysis.

**Common Sorting Algorithms:**
- Quick Sort
- Merge Sort
- Heap Sort
- Counting Sort
- Radix Sort
- Bucket Sort

**When to Choose:**
- **Quick Sort:** General purpose, average case fast
- **Merge Sort:** Stable, guaranteed O(n log n)
- **Heap Sort:** In-place, no worst-case O(n²)
- **Counting Sort:** When range is small
- **Radix Sort:** For integers with fixed digits
- **Built-in Sort:** Usually best choice in practice

---

## Quick Sort

Divide and conquer algorithm with average O(n log n) time.

### Implementation

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;  // Index of smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Wrapper function
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}
```

#### Python Implementation
```python
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def quick_sort_wrapper(arr):
    quick_sort(arr, 0, len(arr) - 1)
```

**Time Complexity:** O(n log n) average, O(n²) worst case  
**Space Complexity:** O(log n) average for recursion stack

---

## Merge Sort

Divide and conquer algorithm with guaranteed O(n log n) time, stable.

### Implementation

#### C++ Implementation
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}
```

#### Python Implementation
```python
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    
    left_arr = arr[left:mid + 1]
    right_arr = arr[mid + 1:right + 1]
    
    i = j = 0
    k = left
    
    while i < n1 and j < n2:
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1
    
    while i < n1:
        arr[k] = left_arr[i]
        i += 1
        k += 1
    
    while j < n2:
        arr[k] = right_arr[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

def merge_sort_wrapper(arr):
    merge_sort(arr, 0, len(arr) - 1)
```

**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

---

## Heap Sort

Sort using heap data structure, in-place.

### Implementation

#### C++ Implementation
```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

---

## Counting Sort

For integers in a small range.

### Implementation

#### C++ Implementation
```cpp
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;
    
    vector<int> count(range, 0);
    vector<int> output(arr.size());
    
    // Count occurrences
    for (int num : arr) {
        count[num - minVal]++;
    }
    
    // Update count to actual position
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    
    arr = output;
}
```

**Time Complexity:** O(n + k) where k is range  
**Space Complexity:** O(n + k)

---

## Custom Comparators

### C++ Custom Comparator

```cpp
#include <bits/stdc++.h>
using namespace std;

// Sort by absolute value
bool compareAbs(int a, int b) {
    return abs(a) < abs(b);
}

// Sort pairs by second element, then first
bool comparePairs(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

// Using lambda
void customSort(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
}

// Sort in descending order
void descendingSort(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
}
```

### Python Custom Comparator

```python
# Using key function
arr.sort(key=lambda x: abs(x))

# Sort pairs
pairs.sort(key=lambda x: (x[1], x[0]))

# Descending order
arr.sort(reverse=True)

# Custom comparator function
def compare(a, b):
    if abs(a) != abs(b):
        return abs(a) < abs(b)
    return a < b

arr.sort(key=functools.cmp_to_key(compare))
```

---

## STL Sort Functions

### C++ STL

```cpp
#include <algorithm>

vector<int> arr = {3, 1, 4, 1, 5, 9};

// Sort ascending (default)
sort(arr.begin(), arr.end());

// Sort descending
sort(arr.begin(), arr.end(), greater<int>());

// Sort with custom comparator
sort(arr.begin(), arr.end(), compareAbs);

// Partial sort (first k elements)
partial_sort(arr.begin(), arr.begin() + k, arr.end());

// Check if sorted
bool isSorted = is_sorted(arr.begin(), arr.end());
```

### Python Built-in

```python
arr = [3, 1, 4, 1, 5, 9]

# Sort in-place
arr.sort()

# Return sorted copy
sorted_arr = sorted(arr)

# Sort descending
arr.sort(reverse=True)

# Sort with key
arr.sort(key=lambda x: abs(x))

# Check if sorted
is_sorted = arr == sorted(arr)
```

---

## Special Sorting Problems

### Inversion Count (Merge Sort)

Count inversions in array.

#### C++ Implementation
```cpp
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    int inversions = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            inversions += (mid - i + 1);  // All remaining in left subarray
        }
    }
    
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    
    return inversions;
}

int countInversions(vector<int>& arr, int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}
```

---

## Complexity Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable |
|-----------|-----------|--------------|------------|-------|--------|
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(k) | Yes |
| Radix Sort | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) | Yes |

where k is range, d is number of digits

---

## Quick Reference

### When to Use Which Algorithm

- **General purpose:** Built-in sort (STL sort/Arrays.sort)
- **Need stability:** Merge Sort or Counting Sort
- **In-place required:** Quick Sort or Heap Sort
- **Small range integers:** Counting Sort
- **Fixed-digit integers:** Radix Sort
- **Nearly sorted:** Insertion Sort (O(n))

### Common Patterns

1. **Sort by multiple criteria** → Custom comparator
2. **Count inversions** → Merge Sort with counting
3. **K largest/smallest** → Partial sort or heap
4. **Custom ordering** → Lambda functions or comparator classes

---

## Practice Problems

### Easy
- Sort Colors (Dutch National Flag)
- Valid Anagram
- Meeting Rooms
- Sort Array By Parity

### Medium
- Merge Intervals
- Kth Largest Element
- Top K Frequent Elements
- Reorder Data in Log Files

### Hard
- Count of Smaller Numbers After Self (Merge Sort)
- Maximum Gap (Radix Sort)
- Sort List (Merge Sort on Linked List)

---

## External Resources

- [GeeksforGeeks Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
- [LeetCode Sorting Explore](https://leetcode.com/tag/sorting/)
- [CP Algorithms Sorting](https://cp-algorithms.com/sequences/sorting.html)

---

_Last updated: January 2026_


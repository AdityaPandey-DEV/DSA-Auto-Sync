# Greedy Algorithms

## Introduction

Greedy algorithms make locally optimal choices at each step, hoping to find a global optimum. They work when a problem has the greedy choice property and optimal substructure.

**Greedy Choice Property:** A global optimum can be reached by making locally optimal choices.

**Optimal Substructure:** An optimal solution contains optimal solutions to subproblems.

**When to Use Greedy:**
- Activity selection problems
- Interval scheduling
- Fractional knapsack
- Minimum spanning tree
- Shortest path (in certain cases)
- Huffman coding
- Coin change (when greedy works)

**Warning:** Greedy doesn't always work! Need to prove it works for the problem.

---

## Classic Greedy Problems

### Activity Selection Problem

Select maximum number of non-overlapping activities.

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

vector<int> activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);
    
    vector<int> selected;
    selected.push_back(0);  // First activity always selected
    int lastFinish = activities[0].finish;
    
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(i);
            lastFinish = activities[i].finish;
        }
    }
    
    return selected;
}
```

#### Python Implementation
```python
def activity_selection(activities):
    # Sort by finish time
    activities.sort(key=lambda x: x[1])
    
    selected = [0]  # First activity always selected
    last_finish = activities[0][1]
    
    for i in range(1, len(activities)):
        if activities[i][0] >= last_finish:
            selected.append(i)
            last_finish = activities[i][1]
    
    return selected
```

**Time Complexity:** O(n log n) for sorting  
**Space Complexity:** O(1)

---

### Fractional Knapsack

Maximize value with fractional items allowed.

#### C++ Implementation
```cpp
struct Item {
    int value, weight;
    double ratio;  // value/weight
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Calculate value/weight ratio
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }
    
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    
    for (auto& item : items) {
        if (remainingCapacity >= item.weight) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            totalValue += item.value * ((double)remainingCapacity / item.weight);
            break;
        }
    }
    
    return totalValue;
}
```

**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

---

### Interval Scheduling Problems

#### Merge Intervals

#### C++ Implementation
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
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

#### Non-overlapping Intervals

#### C++ Implementation
```cpp
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    // Sort by end time
    sort(intervals.begin(), intervals.end(), 
         [](vector<int>& a, vector<int>& b) {
             return a[1] < b[1];
         });
    
    int count = 0;
    int lastEnd = intervals[0][1];
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < lastEnd) {
            count++;  // Remove this interval
        } else {
            lastEnd = intervals[i][1];
        }
    }
    
    return count;
}
```

---

### Jump Game

#### Jump Game I (Can reach end?)

#### C++ Implementation
```cpp
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) {
            return false;  // Cannot reach position i
        }
        maxReach = max(maxReach, i + nums[i]);
        
        if (maxReach >= nums.size() - 1) {
            return true;
        }
    }
    
    return true;
}
```

#### Jump Game II (Minimum jumps)

#### C++ Implementation
```cpp
int jump(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    
    return jumps;
}
```

---

### Gas Station Problem

#### C++ Implementation
```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    int currentGas = 0;
    int startStation = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += gas[i] - cost[i];
        
        // If we can't reach next station from current start
        if (currentGas < 0) {
            startStation = i + 1;
            currentGas = 0;
        }
    }
    
    return (totalGas >= totalCost) ? startStation : -1;
}
```

---

### Minimum Platforms Required

Find minimum platforms needed so no train waits.

#### C++ Implementation
```cpp
int findPlatform(vector<int>& arrival, vector<int>& departure) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int platforms = 0;
    int maxPlatforms = 0;
    int i = 0, j = 0;
    
    while (i < arrival.size() && j < departure.size()) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;
            maxPlatforms = max(maxPlatforms, platforms);
        } else {
            platforms--;
            j++;
        }
    }
    
    return maxPlatforms;
}
```

---

### Partition Labels

Partition string into as many parts as possible where each letter appears in at most one part.

#### C++ Implementation
```cpp
vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastOccurrence;
    
    // Find last occurrence of each character
    for (int i = 0; i < s.length(); i++) {
        lastOccurrence[s[i]] = i;
    }
    
    vector<int> result;
    int start = 0;
    int end = 0;
    
    for (int i = 0; i < s.length(); i++) {
        end = max(end, lastOccurrence[s[i]]);
        
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    
    return result;
}
```

---

### Assign Cookies

Assign cookies to children to maximize satisfied children.

#### C++ Implementation
```cpp
int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    
    int satisfied = 0;
    int i = 0, j = 0;
    
    while (i < children.size() && j < cookies.size()) {
        if (cookies[j] >= children[i]) {
            satisfied++;
            i++;
        }
        j++;
    }
    
    return satisfied;
}
```

---

### Lemonade Change

#### C++ Implementation
```cpp
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    
    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else {  // bill == 20
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    
    return true;
}
```

---

## Common Greedy Patterns

### Pattern 1: Sort and Process
Many greedy problems involve sorting first, then processing in order.

### Pattern 2: Two Pointers
Use two pointers to process from both ends (e.g., Assign Cookies).

### Pattern 3: Greedy Choice
At each step, make the locally optimal choice (e.g., Activity Selection).

### Pattern 4: Interval Problems
Sort intervals and process greedily (merge, non-overlapping, etc.).

---

## When Greedy Works vs Doesn't Work

### Greedy Works For:
- Activity Selection ✓
- Fractional Knapsack ✓
- Minimum Spanning Tree (Prim, Kruskal) ✓
- Shortest Path (Dijkstra) ✓
- Huffman Coding ✓
- Interval Scheduling ✓

### Greedy Doesn't Work For:
- 0/1 Knapsack ✗ (Need DP)
- Traveling Salesman Problem ✗ (NP-hard)
- Coin Change (general case) ✗ (Need DP)
- Longest Path ✗ (NP-hard)

---

## Proving Greedy Correctness

1. **Greedy Choice Property:** Show that a globally optimal solution can be built by making locally optimal choices.
2. **Optimal Substructure:** Show that an optimal solution contains optimal solutions to subproblems.
3. **Exchange Argument:** Show that any optimal solution can be transformed into the greedy solution without making it worse.

---

## Complexity Analysis

### Time Complexity
- Most greedy algorithms: O(n log n) due to sorting
- Some problems: O(n) if already sorted
- Activity Selection: O(n log n)
- Fractional Knapsack: O(n log n)
- Interval Problems: O(n log n)

### Space Complexity
- Usually: O(1) additional space
- With sorting: O(n) for array copy or O(log n) for recursion stack

---

## Quick Reference

### Greedy Strategy Checklist
- [ ] Problem has greedy choice property?
- [ ] Problem has optimal substructure?
- [ ] Can prove correctness?
- [ ] What should we sort by? (finish time, ratio, start time, etc.)
- [ ] What's the greedy choice? (earliest finish, highest ratio, etc.)

### Common Sorting Keys
- **Activity Selection:** Sort by finish time
- **Interval Problems:** Sort by start or end time
- **Fractional Knapsack:** Sort by value/weight ratio
- **Meeting Rooms:** Sort by start time
- **Non-overlapping Intervals:** Sort by end time

---

## Practice Problems

### Easy
- Assign Cookies
- Lemonade Change
- Best Time to Buy and Sell Stock
- Valid Parentheses String

### Medium
- Jump Game
- Jump Game II
- Gas Station
- Partition Labels
- Merge Intervals
- Non-overlapping Intervals

### Hard
- Candy
- Queue Reconstruction by Height
- Remove K Digits
- Maximum Swap

---

## External Resources

- [GeeksforGeeks Greedy Algorithms](https://www.geeksforgeeks.org/greedy-algorithms/)
- [LeetCode Greedy Explore](https://leetcode.com/tag/greedy/)
- [CP Algorithms Greedy](https://cp-algorithms.com/greedy/)

---

_Last updated: January 2026_


# 📚 Algorithm Notes & Reference

Comprehensive notes on Data Structures and Algorithms for competitive programming and technical interviews.

---

## 📑 Table of Contents

### Core Algorithms

1. **[Dynamic Programming (DP)](dp.md)** ⭐
   - 1D/2D DP, Knapsack, LCS, LIS
   - Memoization and Tabulation
   - Templates in C++ and Python

2. **[Graph Algorithms](graphs.md)** ⭐
   - BFS, DFS, Shortest Paths
   - Dijkstra, Bellman-Ford, Floyd-Warshall
   - MST (Kruskal, Prim), Topological Sort
   - Cycle Detection

3. **[Binary Search](binary-search.md)** ⭐
   - Standard Binary Search
   - Lower/Upper Bound
   - Binary Search on Answer
   - Rotated Array Search

### Essential Techniques

4. **[Array Techniques](arrays.md)**
   - Two Pointers, Sliding Window
   - Prefix Sums, Difference Arrays
   - Kadane's Algorithm
   - Array Manipulation

5. **[String Algorithms](strings.md)**
   - KMP Algorithm
   - Rabin-Karp (Rolling Hash)
   - Trie Data Structure
   - Palindrome Problems

6. **[Tree Algorithms](trees.md)**
   - Tree Traversals (Pre/In/Post/Level)
   - BST Operations
   - Tree Construction
   - LCA, Tree DP

7. **[Heap / Priority Queue](heaps.md)**
   - Min/Max Heap
   - K-th Largest/Smallest
   - Merge K Sorted Lists
   - Heap-based Solutions

8. **[Greedy Algorithms](greedy.md)**
   - Activity Selection
   - Fractional Knapsack
   - Interval Scheduling
   - Greedy Patterns

9. **[Backtracking](backtracking.md)**
   - Permutations & Combinations
   - N-Queens, Sudoku
   - Subset Generation
   - Template Structure

10. **[Sliding Window](sliding-window.md)**
    - Fixed & Variable Window
    - Longest Substring Problems
    - Frequency Counting
    - Window Maximum/Minimum

11. **[Two Pointers](two-pointers.md)**
    - Opposite Ends
    - Same Direction (Fast/Slow)
    - Linked List Problems
    - Array Partitioning

12. **[Bit Manipulation](bit-manipulation.md)**
    - Common Bit Operations
    - XOR Tricks
    - Bitmasking for Subsets
    - Power of 2 Checks

13. **[Sorting Algorithms](sorting.md)**
    - Quick Sort, Merge Sort
    - Heap Sort, Counting Sort
    - Custom Comparators
    - Inversion Count

---

## 🎯 Quick Reference

### By Problem Type

| Problem Type | Algorithm/Techique | Time Complexity |
|-------------|-------------------|-----------------|
| Shortest Path (Unweighted) | BFS | O(V + E) |
| Shortest Path (Weighted, Non-negative) | Dijkstra | O((V + E) log V) |
| Shortest Path (Weighted, Negative allowed) | Bellman-Ford | O(V × E) |
| All Pairs Shortest Path | Floyd-Warshall | O(V³) |
| Minimum Spanning Tree | Kruskal/Prim | O(E log E) / O(E log V) |
| Maximum Subarray Sum | Kadane's Algorithm | O(n) |
| Pattern Matching | KMP | O(n + m) |
| Subset Generation | Backtracking/Bitmasking | O(2^n) |
| K-th Largest Element | Heap | O(n log k) |
| Longest Common Subsequence | DP | O(m × n) |

### By Difficulty

#### Beginner Friendly
- Two Pointers
- Sliding Window (Fixed)
- Basic Sorting
- Simple Backtracking

#### Intermediate
- Dynamic Programming (1D)
- Graph Traversals (BFS/DFS)
- Binary Search
- Heap Operations

#### Advanced
- 2D Dynamic Programming
- Advanced Graph Algorithms
- Tree DP
- Complex Backtracking
- Bit Manipulation Tricks

---

## 📖 Learning Path

### Phase 1: Fundamentals (Week 1-2)
1. [Array Techniques](arrays.md) - Two Pointers, Sliding Window
2. [Sorting Algorithms](sorting.md) - Basic sorting concepts
3. [Two Pointers](two-pointers.md) - Master the technique

### Phase 2: Essential Algorithms (Week 3-4)
4. [Binary Search](binary-search.md) - Search and optimization
5. [String Algorithms](strings.md) - Pattern matching basics
6. [Tree Algorithms](trees.md) - Traversals and BST

### Phase 3: Advanced Topics (Week 5-6)
7. [Dynamic Programming](dp.md) - 1D DP patterns
8. [Graph Algorithms](graphs.md) - BFS, DFS, shortest paths
9. [Greedy Algorithms](greedy.md) - Problem-solving patterns

### Phase 4: Expert Level (Week 7-8)
10. [Backtracking](backtracking.md) - Complex state exploration
11. [Advanced DP](dp.md) - 2D DP, Tree DP
12. [Heap](heaps.md) - Advanced heap applications
13. [Bit Manipulation](bit-manipulation.md) - Optimization techniques

---

## 💡 Quick Tips & Tricks

### Problem-Solving Checklist

1. **Understand the Problem**
   - [ ] Read carefully, identify constraints
   - [ ] What is the input/output format?
   - [ ] What are edge cases?

2. **Identify Approach**
   - [ ] Array/String → Two Pointers, Sliding Window, Prefix Sum
   - [ ] Tree/Graph → BFS/DFS, Tree DP
   - [ ] Optimization → DP or Greedy
   - [ ] Search → Binary Search
   - [ ] Constraint Satisfaction → Backtracking

3. **Optimize**
   - [ ] Time complexity acceptable?
   - [ ] Space complexity acceptable?
   - [ ] Can we reduce space?
   - [ ] Can we optimize further?

4. **Test**
   - [ ] Test with examples
   - [ ] Test edge cases (empty, single element, duplicates)
   - [ ] Test boundary conditions

### Common Patterns

#### Pattern Recognition

- **"Find all combinations"** → Backtracking
- **"Maximum/Minimum subarray"** → Kadane's or Sliding Window
- **"At most K" or "Exactly K"** → Sliding Window
- **"Optimal substructure"** → Dynamic Programming
- **"Overlapping subproblems"** → Dynamic Programming with memoization
- **"Sorted array + search"** → Binary Search
- **"Connected components"** → DFS/BFS
- **"Shortest path"** → BFS (unweighted) or Dijkstra (weighted)
- **"Top K elements"** → Heap

---

## 🔧 Code Templates

### Quick Access Links

- **[DP Templates](dp.md#template-code)** - Memoization and Tabulation
- **[Graph Templates](graphs.md#graph-traversal-algorithms)** - BFS/DFS implementations
- **[Binary Search Templates](binary-search.md#template-code)** - Standard and advanced
- **[Backtracking Template](backtracking.md#backtracking-template)** - Standard structure
- **[Sliding Window Templates](sliding-window.md#template-for-fixed-window)** - Fixed and variable
- **[Two Pointers Templates](two-pointers.md#template)** - All variations

---

## 📊 Complexity Cheat Sheet

### Time Complexity Summary

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| BFS/DFS | O(V + E) | O(V + E) | O(V + E) | O(V) |
| Dijkstra | O(V + E) | O((V+E)log V) | O((V+E)log V) | O(V) |
| DP (1D) | O(n) | O(n) | O(n) | O(n) |
| DP (2D) | O(m×n) | O(m×n) | O(m×n) | O(m×n) |
| KMP | O(n) | O(n+m) | O(n+m) | O(m) |

### Space Complexity Summary

- **Two Pointers:** O(1)
- **Sliding Window:** O(k) where k is window size
- **DFS/BFS:** O(V) for visited array + recursion stack
- **DP Memoization:** O(n) for 1D, O(m×n) for 2D
- **Backtracking:** O(n) for recursion stack + O(n) for current solution

---

## 🎓 Problem Categories

### Array & String
- [Array Techniques](arrays.md)
- [String Algorithms](strings.md)
- [Two Pointers](two-pointers.md)
- [Sliding Window](sliding-window.md)

### Tree & Graph
- [Tree Algorithms](trees.md)
- [Graph Algorithms](graphs.md)

### Dynamic Programming
- [Dynamic Programming](dp.md)
- [Tree DP](trees.md#tree-dp-patterns)

### Searching & Sorting
- [Binary Search](binary-search.md)
- [Sorting Algorithms](sorting.md)

### Advanced Techniques
- [Backtracking](backtracking.md)
- [Greedy Algorithms](greedy.md)
- [Heap](heaps.md)
- [Bit Manipulation](bit-manipulation.md)

---

## 📝 Notes Format

Each algorithm note follows this structure:

1. **Introduction** - Overview and when to use
2. **Core Concepts** - Theory and key ideas
3. **Template Code** - Reusable C++ and Python templates
4. **Common Patterns** - Problem-solving patterns
5. **Examples** - Solved problems with explanations
6. **Complexity Analysis** - Time and space complexity
7. **Quick Reference** - Summary section
8. **Practice Problems** - Links to related problems

All code examples are provided in both **C++** and **Python**.

---

## 🔗 External Resources

### Learning Platforms
- [LeetCode](https://leetcode.com/) - Practice problems
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Tutorials and articles
- [Codeforces](https://codeforces.com/) - Competitive programming contests
- [CP Algorithms](https://cp-algorithms.com/) - Competitive programming algorithms

### Algorithm Visualizations
- [VisuAlgo](https://visualgo.net/) - Visualize algorithms
- [Algorithm Visualizer](https://algorithm-visualizer.org/) - Interactive algorithm visualization

### Practice & Discussion
- [LeetCode Discuss](https://leetcode.com/discuss/) - Solution discussions
- [Codeforces Blog](https://codeforces.com/blog) - Competitive programming insights
- [Reddit r/algorithms](https://www.reddit.com/r/algorithms/) - Algorithm discussions

---

## 🏆 Recommended Practice Order

### Beginner Track
1. Arrays → Two Pointers → Sliding Window
2. Sorting → Binary Search
3. Strings → Basic String Operations
4. Trees → Tree Traversals
5. Basic DP → 1D DP Problems

### Intermediate Track
1. Advanced Arrays → Kadane's, Prefix Sums
2. Graph Algorithms → BFS, DFS, Shortest Paths
3. Advanced DP → 2D DP, Knapsack
4. Greedy → Activity Selection, Intervals
5. Backtracking → Permutations, Combinations

### Advanced Track
1. Advanced Graphs → MST, Topological Sort, Cycle Detection
2. Tree DP → Maximum Path Sum, Diameter
3. Advanced Strings → KMP, Trie, Advanced Matching
4. Bit Manipulation → Bitmasking, XOR Tricks
5. Advanced DP → State Space Reduction, Bitmask DP

---

## 💻 Programming Languages

All algorithms are implemented in:

- **C++** - For competitive programming (fast execution)
- **Python** - For interviews and readability

### Language-Specific Notes

#### C++
- Uses STL containers (`vector`, `unordered_map`, `priority_queue`)
- STL algorithms (`sort`, `lower_bound`, `upper_bound`)
- GCC builtins (`__builtin_popcount`)

#### Python
- Uses built-in collections (`deque`, `defaultdict`)
- List comprehensions and generators
- `heapq` module for heaps
- `bisect` module for binary search

---

## 🔖 Tags & Categories

### By Difficulty
- **Easy:** Basic implementation, simple logic
- **Medium:** Requires algorithm knowledge, optimization needed
- **Hard:** Complex algorithms, multiple concepts combined

### By Topic
- **Arrays** - arrays.md, sliding-window.md, two-pointers.md
- **Strings** - strings.md, arrays.md
- **Trees** - trees.md
- **Graphs** - graphs.md
- **Dynamic Programming** - dp.md, trees.md (Tree DP)
- **Searching** - binary-search.md, arrays.md (Linear Search)
- **Sorting** - sorting.md
- **Advanced** - backtracking.md, bit-manipulation.md, greedy.md

### By Pattern
- **Divide & Conquer** - merge-sort, quick-sort, binary-search
- **Greedy** - greedy.md, heaps.md (some problems)
- **Dynamic Programming** - dp.md, trees.md
- **Backtracking** - backtracking.md
- **Two Pointers** - two-pointers.md, arrays.md, sliding-window.md

---

## 📈 Progress Tracking

Use this checklist to track your learning:

### Fundamentals
- [ ] Master Two Pointers technique
- [ ] Understand Sliding Window patterns
- [ ] Implement all basic sorting algorithms
- [ ] Solve 10+ array problems

### Core Algorithms
- [ ] Master Binary Search (standard and advanced)
- [ ] Understand BFS and DFS deeply
- [ ] Solve 5+ tree problems
- [ ] Solve 5+ graph problems

### Dynamic Programming
- [ ] Understand memoization vs tabulation
- [ ] Solve 10+ 1D DP problems
- [ ] Solve 5+ 2D DP problems
- [ ] Master common DP patterns

### Advanced Topics
- [ ] Master Backtracking template
- [ ] Solve N-Queens and Sudoku
- [ ] Understand Greedy problem identification
- [ ] Master Heap operations
- [ ] Learn Bit Manipulation tricks

---

## 🐛 Common Mistakes & How to Avoid

### Two Pointers
- **Mistake:** Not handling edge cases (empty array, single element)
- **Fix:** Always check array size before processing

### Binary Search
- **Mistake:** Off-by-one errors in boundaries
- **Fix:** Use `left + (right - left) / 2` and be consistent with `<` vs `<=`

### Dynamic Programming
- **Mistake:** Not identifying overlapping subproblems
- **Fix:** Look for recursive solutions that solve same subproblem multiple times

### Backtracking
- **Mistake:** Forgetting to undo changes (backtrack step)
- **Fix:** Always restore state after recursive call

### Graph Algorithms
- **Mistake:** Not marking nodes as visited (infinite loops)
- **Fix:** Always check visited array before processing

---

## 📚 Additional Study Resources

### Books
- **Introduction to Algorithms (CLRS)** - Comprehensive algorithm reference
- **Algorithm Design Manual** - Practical problem-solving guide
- **Cracking the Coding Interview** - Interview-focused algorithms

### Online Courses
- Coursera: Algorithms Specialization (Stanford)
- edX: Introduction to Computer Science (MIT)
- Udemy: Data Structures and Algorithms courses

---

## 🤝 Contributing

Found an error or want to improve these notes?

1. Review the existing content
2. Identify areas for improvement
3. Add more examples or explanations
4. Update complexity analysis if needed
5. Add more practice problems

---

## 📅 Last Updated

All notes are regularly updated with:
- New algorithm variations
- Additional code examples
- Updated complexity analysis
- New practice problems
- Bug fixes and improvements

**Last major update:** January 2026

---

## 🎯 Goals

By studying these notes, you should be able to:

✅ Identify which algorithm/technique to use for a problem  
✅ Implement algorithms correctly in C++ and Python  
✅ Analyze time and space complexity  
✅ Optimize solutions when needed  
✅ Solve LeetCode medium/hard problems confidently  
✅ Perform well in technical interviews  
✅ Participate effectively in competitive programming contests  

---

**Happy Learning! 🚀**

---

_[Back to Main README](../README.md)_


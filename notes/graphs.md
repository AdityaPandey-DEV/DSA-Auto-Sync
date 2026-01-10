# Graph Algorithms

## Introduction

Graph algorithms are fundamental to solving problems involving relationships and connections between entities. Graphs are used to model networks, relationships, dependencies, and many real-world problems.

**Graph Representation:**
- **Adjacency List:** Efficient for sparse graphs (most common)
- **Adjacency Matrix:** Efficient for dense graphs
- **Edge List:** Simple representation for some algorithms

**When to Use Graph Algorithms:**
- Network problems (social networks, computer networks)
- Pathfinding problems
- Dependency resolution
- Cycle detection
- Connected components
- Shortest path problems

---

## Core Concepts

### Graph Types
- **Directed Graph (Digraph):** Edges have direction
- **Undirected Graph:** Edges have no direction
- **Weighted Graph:** Edges have weights/costs
- **Unweighted Graph:** All edges have equal weight
- **DAG (Directed Acyclic Graph):** No cycles in directed graph
- **Tree:** Connected acyclic graph
- **Bipartite Graph:** Vertices can be divided into two sets

### Graph Properties
- **Degree:** Number of edges incident to a vertex
- **Path:** Sequence of vertices connected by edges
- **Cycle:** Path that starts and ends at the same vertex
- **Connected Component:** Maximal connected subgraph
- **Spanning Tree:** Tree that includes all vertices

---

## Graph Traversal Algorithms

### Breadth-First Search (BFS)
Explores graph level by level, uses a queue.

**Use Cases:**
- Shortest path in unweighted graphs
- Level-order traversal
- Finding connected components
- Bipartite graph checking

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

// BFS for unweighted graph
void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Process node
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// BFS with distance tracking (shortest path)
vector<int> bfsShortestPath(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, -1);
    queue<int> q;
    
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    return distance;
}
```

#### Python Implementation
```python
from collections import deque

def bfs(graph, start):
    n = len(graph)
    visited = [False] * n
    queue = deque([start])
    visited[start] = True
    
    while queue:
        node = queue.popleft()
        print(node, end=" ")  # Process node
        
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

def bfs_shortest_path(graph, start):
    n = len(graph)
    distance = [-1] * n
    queue = deque([start])
    distance[start] = 0
    
    while queue:
        node = queue.popleft()
        
        for neighbor in graph[node]:
            if distance[neighbor] == -1:
                distance[neighbor] = distance[node] + 1
                queue.append(neighbor)
    
    return distance
```

### Depth-First Search (DFS)
Explores graph as deep as possible, uses recursion/stack.

**Use Cases:**
- Path finding
- Cycle detection
- Topological sorting
- Connected components
- Tree traversals

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

// DFS recursive
void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";  // Process node
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

// DFS iterative (using stack)
void dfsIterative(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;
    
    st.push(start);
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";  // Process node
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}
```

#### Python Implementation
```python
# DFS recursive
def dfs(graph, node, visited):
    visited[node] = True
    print(node, end=" ")  # Process node
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(graph, neighbor, visited)

# DFS iterative
def dfs_iterative(graph, start):
    n = len(graph)
    visited = [False] * n
    stack = [start]
    
    while stack:
        node = stack.pop()
        
        if not visited[node]:
            visited[node] = True
            print(node, end=" ")  # Process node
            
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    stack.append(neighbor)
```

---

## Shortest Path Algorithms

### Dijkstra's Algorithm
Finds shortest path from source to all vertices in weighted graph (non-negative weights).

**Time Complexity:** O((V + E) log V) with priority queue

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
    
    distance[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (dist > distance[node]) continue;
        
        for (auto [neighbor, weight] : graph[node]) {
            int newDist = dist + weight;
            if (newDist < distance[neighbor]) {
                distance[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
    
    return distance;
}
```

#### Python Implementation
```python
import heapq

def dijkstra(graph, start):
    n = len(graph)
    distance = [float('inf')] * n
    pq = [(0, start)]
    distance[start] = 0
    
    while pq:
        dist, node = heapq.heappop(pq)
        
        if dist > distance[node]:
            continue
        
        for neighbor, weight in graph[node]:
            new_dist = dist + weight
            if new_dist < distance[neighbor]:
                distance[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))
    
    return distance
```

### Bellman-Ford Algorithm
Finds shortest path allowing negative weights, detects negative cycles.

**Time Complexity:** O(V × E)

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<pair<int, int>>>& edges, int n, int start) {
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;
    
    // Relax edges V-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    for (auto [u, v, w] : edges) {
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            // Negative cycle detected
            return {};
        }
    }
    
    return distance;
}
```

### Floyd-Warshall Algorithm
Finds shortest path between all pairs of vertices.

**Time Complexity:** O(V³)

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    return dist;
}
```

#### Python Implementation
```python
def floyd_warshall(graph):
    n = len(graph)
    dist = [row[:] for row in graph]
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    return dist
```

---

## Minimum Spanning Tree (MST)

### Kruskal's Algorithm
Uses Union-Find (DSU) to build MST by adding edges in increasing weight order.

**Time Complexity:** O(E log E)

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

int kruskal(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), 
         [](const vector<int>& a, const vector<int>& b) {
             return a[2] < b[2];
         });
    
    DSU dsu(n);
    int mstWeight = 0;
    
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dsu.unite(u, v)) {
            mstWeight += w;
        }
    }
    
    return mstWeight;
}
```

### Prim's Algorithm
Grows MST from a starting vertex, uses priority queue.

**Time Complexity:** O(E log V)

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

int prim(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
    
    int mstWeight = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (inMST[node]) continue;
        
        inMST[node] = true;
        mstWeight += weight;
        
        for (auto [neighbor, w] : graph[node]) {
            if (!inMST[neighbor]) {
                pq.push({w, neighbor});
            }
        }
    }
    
    return mstWeight;
}
```

#### Python Implementation
```python
import heapq

def prim(graph, start):
    n = len(graph)
    in_mst = [False] * n
    pq = [(0, start)]
    mst_weight = 0
    
    while pq:
        weight, node = heapq.heappop(pq)
        
        if in_mst[node]:
            continue
        
        in_mst[node] = True
        mst_weight += weight
        
        for neighbor, w in graph[node]:
            if not in_mst[neighbor]:
                heapq.heappush(pq, (w, neighbor))
    
    return mst_weight
```

---

## Advanced Graph Algorithms

### Topological Sort
Orders vertices in a DAG such that for every edge (u, v), u comes before v.

#### C++ Implementation (DFS)
```cpp
#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(vector<vector<int>>& graph, int node, 
                       vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(graph, neighbor, visited, result);
        }
    }
    
    result.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortDFS(graph, i, visited, result);
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// Kahn's Algorithm (BFS approach)
vector<int> topologicalSortKahn(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result;
}
```

### Cycle Detection

#### Detect Cycle in Directed Graph (DFS)
```cpp
bool hasCycleDFS(vector<vector<int>>& graph, int node, 
                 vector<int>& color) {
    color[node] = 1;  // Gray (being processed)
    
    for (int neighbor : graph[node]) {
        if (color[neighbor] == 1) return true;  // Back edge found
        if (color[neighbor] == 0 && hasCycleDFS(graph, neighbor, color)) {
            return true;
        }
    }
    
    color[node] = 2;  // Black (processed)
    return false;
}

bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0);  // 0=white, 1=gray, 2=black
    
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && hasCycleDFS(graph, i, color)) {
            return true;
        }
    }
    return false;
}
```

#### Detect Cycle in Undirected Graph
```cpp
bool hasCycleUndirected(vector<vector<int>>& graph, int node, 
                        int parent, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (hasCycleUndirected(graph, neighbor, node, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;  // Back edge to non-parent
        }
    }
    
    return false;
}
```

### Connected Components

#### Find Connected Components (DFS)
```cpp
void findComponents(vector<vector<int>>& graph, int node, 
                   vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            findComponents(graph, neighbor, visited, component);
        }
    }
}

vector<vector<int>> connectedComponents(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            findComponents(graph, i, visited, component);
            components.push_back(component);
        }
    }
    
    return components;
}
```

---

## Complexity Analysis

### Time Complexity
- **BFS/DFS:** O(V + E)
- **Dijkstra:** O((V + E) log V)
- **Bellman-Ford:** O(V × E)
- **Floyd-Warshall:** O(V³)
- **Kruskal:** O(E log E)
- **Prim:** O(E log V)
- **Topological Sort:** O(V + E)

### Space Complexity
- **Adjacency List:** O(V + E)
- **Adjacency Matrix:** O(V²)
- **BFS/DFS:** O(V) for visited array
- **Dijkstra:** O(V) for distance array
- **Kruskal:** O(V) for DSU

---

## Quick Reference

### Graph Problem Identification
- **Path finding** → BFS/DFS, Dijkstra, Bellman-Ford
- **All pairs shortest path** → Floyd-Warshall
- **Minimum spanning tree** → Kruskal, Prim
- **Cycle detection** → DFS with coloring
- **Topological ordering** → Topological sort
- **Connected components** → DFS/BFS
- **Bipartite check** → BFS with coloring

### Template Selection Guide
- **Unweighted, shortest path** → BFS
- **Weighted, non-negative** → Dijkstra
- **Weighted, negative allowed** → Bellman-Ford
- **All pairs** → Floyd-Warshall
- **MST from edges** → Kruskal
- **MST from graph** → Prim
- **DAG ordering** → Topological sort

---

## Practice Problems

### Easy
- Number of Islands (BFS/DFS)
- Clone Graph (BFS)
- Course Schedule (Topological Sort)
- Valid Path (BFS)

### Medium
- Shortest Path in Binary Matrix (BFS)
- Network Delay Time (Dijkstra)
- Cheapest Flights Within K Stops (Bellman-Ford variant)
- Min Cost to Connect All Points (Prim/Kruskal)
- Redundant Connection (Union-Find)

### Hard
- Word Ladder II (BFS with path tracking)
- Network Delay Time (Dijkstra)
- Critical Connections (Tarjan's algorithm)
- Minimum Weight Path (Floyd-Warshall)
- Traveling Salesman Problem (DP on bitmask)

---

## External Resources

- [GeeksforGeeks Graph Tutorial](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
- [CP Algorithms Graphs](https://cp-algorithms.com/graph/)
- [LeetCode Graph Explore](https://leetcode.com/tag/graph/)

---

_Last updated: January 2026_


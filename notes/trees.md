# Tree Algorithms

## Introduction

Trees are hierarchical data structures fundamental to many algorithms. This guide covers essential tree algorithms and techniques.

**Tree Types:**
- Binary Tree
- Binary Search Tree (BST)
- AVL Tree (Self-balancing)
- Segment Tree
- Trie (also covered in strings)

**Key Concepts:**
- Tree Traversals
- BST Operations
- Tree Construction
- LCA (Lowest Common Ancestor)
- Tree DP Patterns

---

## Tree Representation

### Node Structure

#### C++ Definition
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

#### Python Definition
```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

---

## Tree Traversals

### Inorder Traversal (Left-Root-Right)

#### C++ Implementation (Recursive)
```cpp
void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}
```

#### C++ Implementation (Iterative)
```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* current = root;
    
    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        
        current = st.top();
        st.pop();
        result.push_back(current->val);
        current = current->right;
    }
    
    return result;
}
```

#### Python Implementation
```python
def inorder(root, result):
    if root is None:
        return
    
    inorder(root.left, result)
    result.append(root.val)
    inorder(root.right, result)

def inorder_iterative(root):
    result = []
    stack = []
    current = root
    
    while current or stack:
        while current:
            stack.append(current)
            current = current.left
        
        current = stack.pop()
        result.append(current.val)
        current = current.right
    
    return result
```

### Preorder Traversal (Root-Left-Right)

#### C++ Implementation
```cpp
void preorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

// Iterative
vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    
    vector<int> result;
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    
    return result;
}
```

### Postorder Traversal (Left-Right-Root)

#### C++ Implementation
```cpp
void postorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

// Iterative
vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    
    vector<int> result;
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

### Level Order Traversal (BFS)

#### C++ Implementation
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(level);
    }
    
    return result;
}
```

#### Python Implementation
```python
from collections import deque

def level_order(root):
    if root is None:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level = []
        size = len(queue)
        
        for _ in range(size):
            node = queue.popleft()
            level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level)
    
    return result
```

---

## Binary Search Tree (BST) Operations

### Search in BST

#### C++ Implementation
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

// Iterative
TreeNode* searchBSTIterative(TreeNode* root, int val) {
    TreeNode* current = root;
    
    while (current != nullptr && current->val != val) {
        if (val < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return current;
}
```

### Insert in BST

#### C++ Implementation
```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}
```

### Delete from BST

#### C++ Implementation
```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }
        
        // Node has two children
        TreeNode* minNode = findMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    }
    
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
```

### Validate BST

#### C++ Implementation
```cpp
bool isValidBST(TreeNode* root) {
    return validateBST(root, LONG_MIN, LONG_MAX);
}

bool validateBST(TreeNode* root, long minVal, long maxVal) {
    if (root == nullptr) return true;
    
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    
    return validateBST(root->left, minVal, root->val) &&
           validateBST(root->right, root->val, maxVal);
}
```

---

## Tree Construction Problems

### Build Tree from Preorder and Inorder

#### C++ Implementation
```cpp
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> indexMap;
    for (int i = 0; i < inorder.size(); i++) {
        indexMap[inorder[i]] = i;
    }
    
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex, indexMap);
}

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                         int inStart, int inEnd, int& preIndex,
                         unordered_map<int, int>& indexMap) {
    if (inStart > inEnd) return nullptr;
    
    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);
    
    int rootIndex = indexMap[rootVal];
    
    root->left = buildTreeHelper(preorder, inorder, inStart, rootIndex - 1, preIndex, indexMap);
    root->right = buildTreeHelper(preorder, inorder, rootIndex + 1, inEnd, preIndex, indexMap);
    
    return root;
}
```

### Build Tree from Postorder and Inorder

#### C++ Implementation
```cpp
TreeNode* buildTreeFromPostIn(vector<int>& postorder, vector<int>& inorder) {
    unordered_map<int, int> indexMap;
    for (int i = 0; i < inorder.size(); i++) {
        indexMap[inorder[i]] = i;
    }
    
    int postIndex = postorder.size() - 1;
    return buildTreePostHelper(postorder, inorder, 0, inorder.size() - 1, postIndex, indexMap);
}

TreeNode* buildTreePostHelper(vector<int>& postorder, vector<int>& inorder,
                              int inStart, int inEnd, int& postIndex,
                              unordered_map<int, int>& indexMap) {
    if (inStart > inEnd) return nullptr;
    
    int rootVal = postorder[postIndex--];
    TreeNode* root = new TreeNode(rootVal);
    
    int rootIndex = indexMap[rootVal];
    
    root->right = buildTreePostHelper(postorder, inorder, rootIndex + 1, inEnd, postIndex, indexMap);
    root->left = buildTreePostHelper(postorder, inorder, inStart, rootIndex - 1, postIndex, indexMap);
    
    return root;
}
```

---

## Lowest Common Ancestor (LCA)

### LCA in BST

#### C++ Implementation
```cpp
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestorBST(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestorBST(root->right, p, q);
    } else {
        return root;
    }
}
```

### LCA in Binary Tree

#### C++ Implementation
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left != nullptr && right != nullptr) {
        return root;
    }
    
    return left != nullptr ? left : right;
}
```

---

## Tree DP Patterns

### Maximum Path Sum

#### C++ Implementation
```cpp
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (root == nullptr) return 0;
    
    int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
    int rightSum = max(0, maxPathSumHelper(root->right, maxSum));
    
    int currentPathSum = root->val + leftSum + rightSum;
    maxSum = max(maxSum, currentPathSum);
    
    return root->val + max(leftSum, rightSum);
}
```

### Diameter of Binary Tree

#### C++ Implementation
```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int height(TreeNode* root, int& diameter) {
    if (root == nullptr) return 0;
    
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);
    
    diameter = max(diameter, leftHeight + rightHeight);
    
    return 1 + max(leftHeight, rightHeight);
}
```

---

## Segment Tree Basics

### Segment Tree Implementation

#### C++ Implementation (Range Sum Query)
```cpp
class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2 * node, start, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }
    
public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }
    
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
```

---

## Complexity Analysis

### Time Complexity
- **Tree Traversals:** O(n) where n is number of nodes
- **BST Search/Insert/Delete:** O(log n) average, O(n) worst
- **Tree Construction:** O(n)
- **LCA:** O(n) for binary tree, O(log n) for BST
- **Tree DP:** O(n)
- **Segment Tree:** O(n) build, O(log n) query/update

### Space Complexity
- **Recursive Traversals:** O(h) where h is height (O(n) worst)
- **Iterative Traversals:** O(n) for stack/queue
- **BST Operations:** O(h)
- **Tree DP:** O(h) recursion stack
- **Segment Tree:** O(n)

---

## Quick Reference

### Traversal Selection
- **Inorder:** For BST, gives sorted order
- **Preorder:** For tree serialization, copy tree
- **Postorder:** For deletion, expression evaluation
- **Level Order:** For BFS problems, level-wise processing

### Common Patterns
1. **Tree path problems** → DFS with backtracking
2. **Level-wise problems** → BFS (level order)
3. **BST problems** → Use BST property for optimization
4. **Tree construction** → Recursive divide and conquer
5. **Tree DP** → Bottom-up or top-down with memoization

---

## Practice Problems

### Easy
- Maximum Depth of Binary Tree
- Same Tree
- Symmetric Tree
- Invert Binary Tree

### Medium
- Binary Tree Level Order Traversal
- Construct Binary Tree from Preorder and Inorder
- Validate Binary Search Tree
- Lowest Common Ancestor
- Path Sum II

### Hard
- Binary Tree Maximum Path Sum
- Serialize and Deserialize Binary Tree
- Binary Tree Postorder Traversal (Iterative)
- Recover Binary Search Tree

---

## External Resources

- [GeeksforGeeks Tree Tutorial](https://www.geeksforgeeks.org/binary-tree-data-structure/)
- [LeetCode Tree Explore](https://leetcode.com/tag/tree/)
- [CP Algorithms Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)

---

_Last updated: January 2026_


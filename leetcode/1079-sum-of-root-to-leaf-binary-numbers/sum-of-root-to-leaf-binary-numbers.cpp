/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int rec(TreeNode* node,int curr){
        if(!node) return 0;
        curr=curr *2+node->val;
        if(!node->left&&!node->right){
            return curr;
        }
        return rec(node->left,curr)+rec(node->right,curr);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return rec(root,0);
    }
};
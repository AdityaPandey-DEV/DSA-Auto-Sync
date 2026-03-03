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
    int maxdep(TreeNode* root ,int size){
        if (!root) return size;
        size=size+1;
        int ls,rs;
        if(root->left){
            ls=maxdep(root->left,size);
        }
        else{
            ls=size;
        }
        if(root->right){
            rs=maxdep(root->right,size);
        }
        else{
            rs=size;
        }
        return max(ls,rs);
    }
public:
    int maxDepth(TreeNode* root) {
        return maxdep(root,0);


        
    }
};
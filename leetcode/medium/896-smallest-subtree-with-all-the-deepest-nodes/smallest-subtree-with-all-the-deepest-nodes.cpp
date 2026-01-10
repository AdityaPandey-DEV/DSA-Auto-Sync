class Solution {
    pair<TreeNode*, int> dept(TreeNode* root) {
        if (!root) return {nullptr, 0};

        auto L = dept(root->left);
        auto R = dept(root->right);

        if (L.second == R.second) {
            return {root, L.second + 1};
        }
        if (L.second > R.second) {
            return {L.first, L.second + 1};
        }
        return {R.first, R.second + 1};
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dept(root).first;
    }
};
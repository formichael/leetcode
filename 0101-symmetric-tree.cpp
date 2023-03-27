class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root->left, root->right);
    }

    bool dfs(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        
        if (!left || !right)
            return false;

        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode* root, vector<int> &ans) {
        if (!root)
            return;

        ans.push_back(root->val);

        if (root->left)
            helper(root->left, ans);

        if (root->right)
            helper(root->right, ans);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode* root, vector<int> &ans) {
        if (!root)
            return;

        if (root->left)
            helper(root->left, ans);

        if (root->right)
            helper(root->right, ans);

        ans.push_back(root->val);
    }
};

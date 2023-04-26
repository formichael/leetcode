class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int sum, int &ans) {
        sum = sum * 10 + root->val;

        if (!root->left && !root->right) {
            ans += sum;
            return;
        } 

        if (root->left)
            dfs(root->left, sum, ans);

        if (root->right)
            dfs(root->right, sum, ans);
    }
};

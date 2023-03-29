class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
            
        bool found = false;
        dfs(root, targetSum, 0, found);
        return found;
    }

    void dfs(TreeNode* root, int targetSum, int curSum, bool &found) {
        if (found)
            return;

        if (!root) {
            found = curSum == targetSum;
            return;
        }

        curSum += root->val;
        if (!root->left && !root->right) {
            found = curSum == targetSum;
            return;
        }

        if (root->left)
            dfs(root->left, targetSum, curSum, found);

        if (root->right)
            dfs(root->right, targetSum, curSum, found);
    }
};

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
public:
    

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, 0, move(path), ans);
        return ans;
    }

    void dfs(TreeNode* root, int targetSum, int curSum, vector<int> &&path,  vector<vector<int>> &ans) {
        if (!root)
            return;
        
        curSum += root->val;
        path.push_back(root->val);

        if (!root->left && !root->right && curSum == targetSum) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        dfs(root->left, targetSum, curSum, move(path), ans);
        dfs(root->right, targetSum, curSum, move(path), ans);
        path.pop_back();
    }
};

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            ans.emplace_back();

            for (int i = q.size(); i > 0 ; i--) {
                TreeNode *node = q.front();
                ans.back().push_back(node->val);
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

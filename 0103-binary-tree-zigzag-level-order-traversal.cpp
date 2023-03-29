class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode*> q({root});
        bool zigzag = false;

        while (q.size()) {
            ans.emplace_back();

            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                ans.back().push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            if (zigzag) {
                reverse(ans.back().begin(), ans.back().end());
            }

            zigzag = !zigzag;
        }

        return ans;    
    }
};

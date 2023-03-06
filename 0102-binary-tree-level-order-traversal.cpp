class Solution {
public:
    void doLevelOrder(TreeNode* root, int level, vector<vector<int>> &out)
    {
        if (!root)
            return;

        if (out.size() < level) {
            vector<int> v;
            out.push_back(v);
        }

        out[level - 1].push_back(root->val);

        doLevelOrder(root->left, level + 1, out);
        doLevelOrder(root->right, level + 1, out);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        int level = 1;
        doLevelOrder(root, level, out);
        return out;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> out;
        queue<TreeNode *> q({root});

        while (q.size()) {
            out.emplace_back();
            
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();

                if (node) out.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return out;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            ans.push_back(q.back()->val);

            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;    
    }
};

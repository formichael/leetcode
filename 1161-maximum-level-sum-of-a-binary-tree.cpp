// BFS

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxSum = root->val, level = 0;
        queue<TreeNode*> q({root});

        while (!q.empty()) {
            int n = q.size(), sum = 0;
            ++level;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();
                
                if (node->left) 
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (sum > maxSum) {
                ans = level;
                maxSum = sum;
            }
        }

        return ans;
    }
};

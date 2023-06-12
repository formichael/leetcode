class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> nums;
        tree2vec(root, nums);
        for (int i = 1; i < nums.size(); i++) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }

    void tree2vec(TreeNode* root, vector<int> &nums) {
        if (!root)
            return;

        tree2vec(root->left, nums);
        nums.push_back(root->val);
        tree2vec(root->right, nums);
    }
};

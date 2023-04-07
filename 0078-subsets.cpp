class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        backtrack(nums, 0, subset, ans);
        return ans;    
    }

    void backtrack(vector<int>& nums, int idx, vector<int> &subset, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        backtrack(nums, idx + 1, subset, ans);
        subset.pop_back();

        backtrack(nums, idx + 1, subset, ans);
    }
};

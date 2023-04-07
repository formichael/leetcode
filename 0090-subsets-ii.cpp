class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(0, subset, nums, ans);
        return ans;    
    }

    void backtrack(int idx, vector<int> &subset, vector<int>& nums, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // subset include nums[idx]
        subset.push_back(nums[idx]);
        backtrack(idx + 1, subset, nums, ans);

        // subset not include nums[idx]
        subset.pop_back();
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1])
            ++idx;
        backtrack(idx + 1, subset, nums, ans);
    }
};

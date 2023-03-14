class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> elem;
        vector<bool> used(nums.size());
        backtracking(nums, elem, used);
        return ans;
    }

    void backtracking(vector<int>& nums, vector<int> &elem, vector<bool> &used) {
        if (elem.size() == nums.size()) {
            ans.push_back(elem);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            elem.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, elem, used);
            elem.pop_back();
            used[i] = false;
        }
    }
};

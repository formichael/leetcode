class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 4) {
            return ans;
        }

        set<vector<int>> ans1;
        int left = 0, right = 0, sum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 3; ++i) {
            for (int j = i + 1; j < len - 2; ++j) {
                left = j + 1;
                right = len - 1;
                int64_t sum = nums[i] + nums[j];
                while (left < right) {
                    int64_t diff = sum + int64_t(nums[left]) + int64_t(nums[right]) - (int64_t)target;
                    if (diff < 0) {
                        ++left;
                    } else if (diff > 0) {
                        --right;
                    } else {
                        ans1.insert({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                    }
                }
            }
        }

        if (!ans1.empty()) {
            ans.assign(ans1.begin(), ans1.end());
        }
        
        return ans;
    }
};

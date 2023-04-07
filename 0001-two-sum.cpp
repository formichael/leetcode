class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m; // num -> idx

        for (int i = 0; i < nums.size(); ++i) {
            if (auto itr = m.find(target - nums[i]); itr != m.end()) {
                return {itr->second, i};
            }
            m[nums[i]] = i;
        }

        return {};
    }
};

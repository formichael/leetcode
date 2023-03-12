class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (nums[i] < 0)
                nums[i] = 0;
        }

        for (int i = 0; i < len; ++i) {
            auto v = abs(nums[i]);
            if (v < 1 || v > len) {
                continue;
            }

            auto idx = v - 1;
            if (nums[idx] > 0) {
                nums[idx] *= -1;
            } else if (nums[idx] == 0){
                nums[idx] = -v;
            }
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }

        return len + 1;
    }
};

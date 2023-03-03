class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }

        int tmp = 0, min = -1, k = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                min = nums[i + 1];
                k = i + 1;

                // find min num which > nums[i]
                for (int j = i + 2; j < nums.size(); ++j) {
                    if (nums[j] > nums[i] && nums[j] < min) {
                        min = nums[j];
                        k = j;
                    }
                }

                tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;

                // sort nums[i+1:]
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        // nums in decreasing order
        sort(nums.begin(), nums.end());
    }
};

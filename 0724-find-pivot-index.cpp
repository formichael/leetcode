class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum - nums[i] - leftSum == leftSum) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};

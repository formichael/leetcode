class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int minVal = 1, maxVal = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                minVal = 1;
                maxVal = 1;
                ans = max(ans, 0);
            }
            else {
                int a = minVal * nums[i];
                int b = maxVal * nums[i];
                minVal = min({a, b, nums[i]});
                maxVal = max({a, b, nums[i]});
                ans = max(ans, maxVal);
            }
        }
        return ans;
    }
};

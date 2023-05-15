class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 0);

        for (int i = 0; i < N; i++) {
            if (i == 0 || i == 1) {
                dp[i] = nums[i];
            }
            else if (i - 3 >= 0) {
                dp[i] += (max(dp[i - 3], dp[i - 2]) + nums[i]);
            }
            else {
                dp[i] += (dp[i - 2] + nums[i]);
            }
        }

        return N > 1 ? max(dp[N - 2], dp[N - 1]) : dp[N - 1];
    }
};

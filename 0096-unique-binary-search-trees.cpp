class Solution {
public:
    int numTrees(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        return helper(n, dp);        
    }

    int helper(int n, vector<int> &dp) {
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            int left = max(1, i - 1);
            int right = max(1, n - i);

            if (dp[left] == 0)
                dp[left] = helper(left, dp);
            if (dp[right] == 0)
                dp[right] = helper(right, dp);

            sum += dp[left] * dp[right];
        }

        return sum;
    }
};

// Fibonacci sequence
// dp[i] = dp[i-1] + dp[i-2]
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int pre1 = 1, pre2 = 2, tmp = 0;
        for (int i = 2; i < n; ++i) {
            tmp = pre1 + pre2;
            pre1 = pre2;
            pre2 = tmp;
        }

        return pre2;
    }
};

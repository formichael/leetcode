class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int row = m - 2; row >= 0; --row) {
            for (int col = n - 2; col >= 0; --col) {
                dp[row][col] = dp[row][col+1] + dp[row+1][col];
            }
        }

        return dp[0][0];
    }
};

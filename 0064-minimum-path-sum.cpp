class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                dp[row][col] = grid[row][col];
                
                if (row > 0 && col > 0)
                    dp[row][col] += min(dp[row][col - 1], dp[row - 1][col]);
                else if (row > 0)
                    dp[row][col] += dp[row - 1][col];
                else if (col > 0)
                    dp[row][col] += dp[row][col - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

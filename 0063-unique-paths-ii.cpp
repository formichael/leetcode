class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1)
            return 1 - obstacleGrid[0][0];

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (obstacleGrid[row][col] == 0) {
                    if (col > 0) {
                        dp[col] += dp[col - 1];
                    }
                } else {
                    dp[col] = 0;
                }
            }
        }

        return dp[n - 1];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1)
            return 1 - obstacleGrid[0][0];

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int64_t>> dp(m, vector<int64_t>(n, 0));
        
        // bottom right -> left
        for (int i = n - 1; i >= 0; --i) {
            if (obstacleGrid[m - 1][i] == 1)
                break;
            
            dp[m - 1][i] = 1;
        }

        // right bottom -> top
        for (int i = m - 1; i >= 0; --i) {
            if (obstacleGrid[i][n - 1] == 1)
                break;

            dp[i][n - 1] = 1;
        }

        for (int row = m - 2; row >= 0; --row) {
            for (int col = n - 2; col >= 0; --col) {
                if (obstacleGrid[row][col] == 0) {
                    dp[row][col] = dp[row + 1][col] + dp[row][col + 1];
                }
            }
        }

        return dp[0][0];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1)
            return 1 - obstacleGrid[0][0];

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int64_t> dp(n, 0);
        dp[n - 1] = 1;
        
        for (int row = m - 1; row >= 0; --row) {
            for (int col = n - 1; col >= 0; --col) {
                if (obstacleGrid[row][col] == 0) {
                    if (col < n - 1) {
                        dp[col] += dp[col + 1];
                    }
                } else {
                    dp[col] = 0;
                }
            }
        }

        return dp[0];
    }
};

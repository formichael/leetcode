// dfs failed with "Time Limit Exceeded"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        int m = triangle.size();
        
        for (int row = 0; row < m; ++row) {
            vector<int> v(triangle[row].size(), 0);
            dp.emplace_back(v);
        }

        for (int row = m - 1; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                if (row + 1 == m)
                    dp[row][col] = triangle[row][col];
                else
                    dp[row][col] = triangle[row][col] +  min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }

        return dp[0][0];
    }
};

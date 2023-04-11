class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

        for (int i = 0; i <= M; i++) {
            dp[i][N] = M - i;
        }

        for (int i = 0; i <= N; i++) {
            dp[M][i] = N - i;
        }

        for (int row = M - 1; row >= 0; row--) {
            for (int col = N - 1; col >= 0; col--) {
                if (word1[row] == word2[col]) {
                    dp[row][col] = dp[row + 1][col + 1];
                } else {
                    dp[row][col] = 1 + min({dp[row + 1][col], dp[row][col + 1], dp[row + 1][col + 1]});
                }
            }
        }

        return dp[0][0];
    }
};

/***
	a	b	  c	""
a	1			  3
d		1		  2
c			  0 1
 ""	3	2	1	0
***/

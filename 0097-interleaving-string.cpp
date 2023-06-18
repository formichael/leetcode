class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
            
        vector<vector<int8_t>> cache(s1.size() + 1, vector<int8_t>(s2.size() + 1, 0));
        return dfs(s1, 0, s2, 0, s3, cache);
    }

    bool dfs(string s1, int idx1, string s2, int idx2, string s3, vector<vector<int8_t>> &cache) {
        if (idx1 == s1.size() && idx2 == s2.size())
            return true;

        if (cache[idx1][idx2] != 0)
            return cache[idx1][idx2] != 1;

        if (idx1 < s1.size() && s1[idx1] == s3[idx1 + idx2] && dfs(s1, idx1 + 1, s2, idx2, s3, cache))
            return true;
        if (idx2 < s2.size() && s2[idx2] == s3[idx1 + idx2] && dfs(s1, idx1, s2, idx2 + 1, s3, cache))
            return true;

        cache[idx1][idx2] = 1;
        return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), k = s3.size();
        if (M + N != k)
            return false;
            
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[M][N] = true;

        for (int x = M; x >= 0; x--) {
            for (int y = N; y >= 0; y--) {
                if (x < M && s1[x] == s3[x + y] && dp[x + 1][y]) {
                    dp[x][y] = true;
                }
                if (y < N && s2[y] == s3[x + y] && dp[x][y + 1]) {
                    dp[x][y] = true;
                }
            }
        }

        return dp[0][0];
    }
};

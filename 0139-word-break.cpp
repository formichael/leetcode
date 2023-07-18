class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[N] = true;

        for (int i = N - 1; i >= 0; i--) {
            for (const auto &word : wordDict) {
                int M = word.size();
                if (i + M <= N && s.substr(i, M) == word) {
                    dp[i] = dp[i + M];
                }
                if (dp[i])
                    break;
            }
        }

        return dp[0];
    }
};

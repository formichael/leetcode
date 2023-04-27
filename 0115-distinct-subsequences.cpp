class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> cache(M, vector<int>(N, -1));
        return dfs(s, t, 0, 0, cache);
    }

    int dfs(string &s, string &t, int sIdx, int tIdx, vector<vector<int>> &cache) {
        if (tIdx == t.size())
            return 1;

        if (sIdx == s.size())
            return 0;

        if (cache[sIdx][tIdx] >= 0)
            return cache[sIdx][tIdx];

        if (s[sIdx] == t[tIdx]) {
            cache[sIdx][tIdx] = dfs(s, t, sIdx + 1, tIdx + 1, cache) + dfs(s, t, sIdx + 1, tIdx, cache);
        } else {
            cache[sIdx][tIdx] = dfs(s, t, sIdx + 1, tIdx, cache);
        }

        return cache[sIdx][tIdx];   
    }
};

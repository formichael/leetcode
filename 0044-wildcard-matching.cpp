class Solution {
public:
    bool isMatch(string s, string p) {
         int m = s.size();
         int n = p.size();
         s = " " + s;
         p = " " + p;

         vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
         f[0][0] = true;

         for (int i = 0; i <= m; ++i) {
             for (int j = 1; j <= n; ++j) {
                 if (p[j] == '*')
                     f[i][j] = f[i][j - 1] || (i >= 1 && f[i - 1][j]);
                 else // p[j] == ? || single character
                    if (i >= 1)
                        f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
             }
        }

        return f[m][n];
    }
};

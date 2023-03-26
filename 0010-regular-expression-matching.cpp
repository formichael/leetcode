class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        s = " " + s;
        p = " " + p;
        
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true; // f[i,j] => if s[1~i] matchs p[1~j]

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j < n && p[j + 1] == '*')
                    continue;

                if (i >= 1 && p[j] != '*')
                    f[i][j] = f[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                else if (p[j] == '*')
                    f[i][j] = (j >= 2 && f[i][j-2]) || (i >= 1 && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
            }
        }

        return f[m][n];
    }
};

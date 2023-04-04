class Solution {
public:
    int ans;

    int numDecodings(string s) {
        bool isValid = true;
        helper(s, 0, isValid);
        return isValid ? ans : 0;
    }

    void helper(string s, int idx, bool &isValid) {
        if (!isValid)
            return;

        if (idx == s.size()) {
            ++ans;
            return;
        }

        // choose one character
        if (s[idx] == '0') {
            if (idx == 0 || (s[idx - 1] != '1' && s[idx - 1] != '2') ) {
                isValid = false;
            }
            return;
        } else {
            helper(s, idx + 1, isValid);
        }
            
        
        // choose two characters
        int m = s[idx] - '0';
        int n = s[idx + 1] - '0';
        if (idx + 1 < s.size() && (m == 1 || (m == 2 && n <= 6))) {
            helper(s, idx + 2, isValid);
        }
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        int N = s.size();
        vector<int> dp(N, 0);
        dp[0] = 1;
        
        for (int i = 1; i < N; ++i) {
            int m = s[i - 1] - '0';
            int n = s[i] - '0';

            if (1 <= n && n <= 9) {
                dp[i] += dp[i - 1];
            }

            if ( m == 1 || (m == 2 && n <= 6) ) {
                dp[i] += (i > 1 ? dp[i - 2] : 1);
            }
        }

        return dp[N - 1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        int N = s.size();
        int x = 1, y = 1;
        
        for (int i = 1; i < N; ++i) {
            int m = s[i - 1] - '0';
            int n = s[i] - '0';
            int tmp = 0;

            // xxxm, n
            if (1 <= n && n <= 9) {
                tmp += y;
            }

            // xxx, mn
            if ( m == 1 || (m == 2 && n <= 6) ) {
                tmp += x;
            }

            x = y;
            y = tmp;
        }

        return y;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        bool table[n][n];
        std::memset(table, 0x0, sizeof(table));

        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }

        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // k is the length of substring
        for (int k = 3; k <= n; k++) {
            // finding the start index
            for (int i = 0; i < n - k + 1; i++) {
                // j is the ending index of substring
                int j = i + k - 1;

                if (table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = true;
                    
                    if (k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }

        return std::string(s, start, maxLen);
    }
};

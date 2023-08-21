class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int ws = 1; ws <= s.size() / 2; ws++) {
            int i = 0;
            bool badMatch = false;
            for (i = ws; i < s.size() && !badMatch; i += ws) {
                for (int j = 0; j < ws; j++) {
                    if (s[i + j] != s[j]) {
                        badMatch = true;
                        break;
                    }
                }
            }
            if (!badMatch && i == s.size()) {
                return true;
            }
        }
        return false;
    }
};

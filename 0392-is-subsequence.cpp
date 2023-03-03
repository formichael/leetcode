class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0, i = 0, j = 0;
        int lens = s.size(), lent = t.size();

        while (i < lent && j < lens) {
            if (t[i] == s[j]) {
                ++j;
                ++cnt;
            }

            ++i;
        }

        return cnt == lens;
    }
};

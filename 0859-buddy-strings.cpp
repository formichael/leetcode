class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if (goal.size() != n || n == 1)
            return false;

        int diffCnt = 0;
        char c1 = 0, c2 = 0;
        int cache[26] = {0};

        for (int i = 0; i < n; i++) {
            if (s[i] == goal[i]) {
                cache[s[i] - 'a']++;
            }
            else {
                diffCnt++;
                if (diffCnt > 2)
                    return false;

                if (diffCnt == 1) {
                    c1 = s[i];
                    c2 = goal[i];
                }
                else if (diffCnt == 2) {
                    if (c1 != goal[i] || c2 != s[i])
                        return false;
                }
            }
        }

        if (diffCnt == 1)
            return false;
        else if (diffCnt == 2)
            return true;

        // diffCnt == 0
        for (int i = 0; i < 26; i++) {
            if (cache[i] > 1)
                return true;
        }

        return false;
    }
};

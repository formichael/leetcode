class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s2, t2;

        for (auto c : s) {
            if (c == '#') {
                if (!s2.empty())
                    s2.pop();
            } else {
                s2.push(c);
            }
        }

        for (auto c : t) {
            if (c == '#') {
                if (!t2.empty())
                    t2.pop();
            } else {
                t2.push(c);
            }
        }

        return s2 == t2;
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sL = s.size(), tL = t.size();
        int i = sL - 1, j = tL - 1;

        while (i >= 0 || j >= 0) {
            int backspaceCnt = 0;
            while (i >= 0 && (s[i] == '#' || backspaceCnt > 0)) {
                if (s[i] == '#') 
                    ++backspaceCnt;
                else
                    --backspaceCnt;
                
                --i;
            }

            backspaceCnt = 0;
            while (j >= 0 && (t[j] == '#' || backspaceCnt > 0)) {
                if (t[j] == '#') 
                    ++backspaceCnt;
                else
                    --backspaceCnt;
                
                --j;
            }

            if (i < 0 || j < 0) {
                break;
            }

            if (s[i] != t[j])
                return false;

            --i;
            --j;
        }

        return i == j;
    }
};

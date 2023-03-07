class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        for (int p = 2; p <= n; ++p) {
            int cnt = 0, len = s.size();
            char c = s[0];
            stringstream ss;

            for (int i = 0; i < len; ++i) {
                if (s[i] == c) {
                    ++cnt;
                } else {
                    ss << to_string(cnt) << c;
                    c = s[i];
                    cnt = 1;
                }
            }

            if (cnt > 0) {
                ss << to_string(cnt) << s[len - 1];
            }

            s = ss.str();
        }

        return s;
    }
};
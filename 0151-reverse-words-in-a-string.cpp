class Solution {
public:
    string reverseWords(string s) {
        vector<string> set;
        int start = -1, N = s.size();

        for (int i = 0; i < N; i++) {
            if (s[i] == ' ') {
                if (start != -1) {
                    set.push_back(s.substr(start, i - start));
                    start = -1;
                }
            } else {
                if (start == -1) {
                    start = i;
                }

                if (i == N - 1) {
                    set.push_back(s.substr(start, i - start + 1));
                    break;
                }
            }
        }

        stringstream ss;
        for (int i = set.size() - 1; i >= 0; i--) {
            ss << set[i];
            if (i)
                ss << " ";
        }

        return ss.str();
    }
};

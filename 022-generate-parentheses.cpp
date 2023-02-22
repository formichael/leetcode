class Solution {
public:
    vector<string> out;

    void genPnt(string s, int open, int close, const int n)
    {
        if (open == n && close == n) {
            out.push_back(s);
        }
        if (open < n) {
            genPnt(s + "(", open + 1, close, n);
        }
        if (close < open) {
            genPnt(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        genPnt("", 0, 0, n);
        return out;
    }
};

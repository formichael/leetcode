class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> sub;
        vector<vector<string>> ans;
        helper(s, 0, sub, ans);
        return ans;
    }

    void helper(string s, int start, vector<string> &sub, vector<vector<string>> &ans) {
        if (start == s.size()) {
            ans.push_back(sub);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                sub.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, sub, ans);
                sub.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        for (int i = 0; i < (end - start) / 2 + 1; i++) {
            if (s[start + i] != s[end - i])
                return false;
        }
        return true;
    }
};

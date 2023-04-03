class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int8_t>> memo(s1.size(), vector<int8_t>(s2.size(), -1));
        return helper(s1, 0, s2, 0, s3, 0, memo);
    }

    bool helper(string s1, int idx1, string s2, int idx2, string s3, int idx3, vector<vector<int8_t>> &memo) {
        if (idx1 == s1.size())
            return s2.substr(idx2) == s3.substr(idx3);

        if (idx2 == s2.size())
            return s1.substr(idx1) == s3.substr(idx3);

        if (memo[idx1][idx2] >= 0)
            return memo[idx1][idx2] > 0;

        bool ans = false;

        if (idx1 < s1.size() && s1[idx1] == s3[idx3] && helper(s1, idx1 + 1, s2, idx2, s3, idx3 + 1, memo))
            ans = true;

        if (idx2 < s2.size() && s2[idx2] == s3[idx3] && helper(s1, idx1, s2, idx2 + 1, s3, idx3 + 1, memo))
            ans = true;    
        
        memo[idx1][idx2] = int8_t(ans);

        return ans;
    }
};

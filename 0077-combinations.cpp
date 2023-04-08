class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(1, n, k, comb, ans);
        return ans;    
    }

    void backtrack(int cur, int n, int k, vector<int> &comb, vector<vector<int>> &ans) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        if (cur > n)
            return;

        for (int i = cur; i <= n; ++i) {
            comb.push_back(i);
            backtrack(i + 1, n, k, comb, ans);
            comb.pop_back();
        }
    }
};

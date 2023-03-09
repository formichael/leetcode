class Solution {
public:
    vector<vector<int>> out;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(0, cur, 0, candidates, target);
        return out;
    }

    void dfs(int idx, vector<int> &cur, int total, vector<int>& candidates, int target) {
        if (total == target) {
            out.push_back(cur);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[idx]);
        dfs(idx, cur, total + candidates[idx], candidates, target);
        cur.pop_back();

        dfs(idx + 1, cur, total, candidates, target);
    }
};

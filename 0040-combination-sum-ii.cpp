class Solution {
public:
    vector<vector<int>> out;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b) {return a > b;});
        vector<int> cur;
        dfs(0, cur, 0, candidates, target);
        return out;
    }

    inline int getNextIdx(int idx, vector<int>& candidates)
    {
        for (int i = idx + 1; i < candidates.size(); ++i) {
            if (candidates[i] != candidates[idx]) {
                return i;
            }
        }
        return candidates.size();
    }

    void dfs(int idx, vector<int> &cur, int total, vector<int>& candidates, int target)
    {
        if (total == target) {
            out.push_back(cur);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[idx]);
        dfs(idx + 1, cur, total + candidates[idx], candidates, target);
        cur.pop_back();

        int nextIdx = getNextIdx(idx, candidates);
        dfs(nextIdx, cur, total, candidates, target);
    }
};

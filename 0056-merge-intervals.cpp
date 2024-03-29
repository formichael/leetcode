class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (right >= intervals[i][0]) {
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
                continue;
            }
            ans.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }

        ans.push_back({left, right});

        return ans;
    }
};

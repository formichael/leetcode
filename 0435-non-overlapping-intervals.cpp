class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &v, const vector<int> &v2) -> bool {
            return v[0] < v2[0];
        });

        int ans = 0;

        int stop = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= stop) {
                stop = intervals[i][1];
                continue;
            }
            ++ans;
            stop = min(stop, intervals[i][1]);
        }

        return ans;
    }
};

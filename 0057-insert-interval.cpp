class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            }
            
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else
                newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        }

        ans.push_back(newInterval);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};
        if (newInterval.empty())
            return intervals;

        if (newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if (intervals[intervals.size() - 1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int left = newInterval[0], right = newInterval[1];
        bool overlaped = false;
        vector<vector<int>> ans;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if ( (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1]) ||
                 (intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1]) ||
                 (newInterval[0] <= intervals[i][0] && intervals[i][0] <= newInterval[1]) ||
                 (newInterval[0] <= intervals[i][1] && intervals[i][1] <= newInterval[1]) ) {
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
                if (!overlaped) overlaped = true;

                continue;
            } 
            
            if (overlaped) {
                ans.push_back({left, right});
                overlaped = false;
                ans.push_back(intervals[i]);
            } else if (i < intervals.size() - 1 && intervals[i][1] < newInterval[0] && newInterval[1] < intervals[i+1][0]) {
                ans.push_back(intervals[i]);
                ans.push_back({left, right});
            } else {
                ans.push_back(intervals[i]);
            }
        }

        if (overlaped)
            ans.push_back({left, right});

        return ans;
    }
};

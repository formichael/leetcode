class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0, right = 0;
        vector<int> dict(128, -1);

        while (right < s.size()) {
            auto chr = s[right];
            if (dict[chr] == -1) {
                dict[chr] = right;
            } else {
                left = max(left, dict[chr] + 1);
                dict[chr] = right;
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};

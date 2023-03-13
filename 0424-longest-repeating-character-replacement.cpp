class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        constexpr int letterLen = 26;
        int cnts[letterLen] = {0};
        int left = 0, right = 0;
        int maxCnt = 0;

        while (right < s.size()) {
            cnts[s[right] - 'A']++;
            maxCnt = max(maxCnt, *max_element(cnts, cnts + letterLen));

            while (right - left + 1 - maxCnt > k) {
                cnts[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};

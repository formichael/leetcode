class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int N = columnTitle.size();
        for (int i = N - 1; i >= 0; i--) {
            ans += int(columnTitle[i] - 'A' + 1) * pow(26, N - 1 - i);
        }
        return ans;
    }
};

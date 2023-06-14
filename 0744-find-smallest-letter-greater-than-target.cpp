// binary search

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target) {
                high = mid - 1;
                ans = min(ans, mid);
            }
            else {
                low = mid + 1;
            }
        }

        if (ans == n)
            ans = 0;

        return letters[ans];
    }
};

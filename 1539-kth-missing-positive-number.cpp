class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = arr[0];
        if (k < start)
            return k;

        int missing = start - 1;
        int i = 1; // arr's index
        while (missing < k) {
            ++start;
            if (i >= arr.size() || start < arr[i]) {
                ++missing;
            } else {
                ++i;
            }
        }

        return start;
    }
};

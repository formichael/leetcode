class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = 1<<16;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int64_t pow = int64_t(mid) * int64_t(mid);

            if (pow == int64_t(x)) {
                return mid;
            } else if (pow < int64_t(x)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low - 1;
    }
};

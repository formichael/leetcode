class Solution {
public:
    bool judgeSquareSum(int c) {
        int64_t a = 0;
        int64_t b = std::sqrt(c);
        int64_t sum = 0, d = c;

        while (a <= b) {
            sum = a * a + b * b;
            if (sum < d) {
                ++a;
            } else if (sum > d) {
                --b;
            } else { // sum == d
                return true;
            }
        }

        return false;
    }
};

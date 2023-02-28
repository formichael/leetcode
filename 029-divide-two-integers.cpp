class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            else if (divisor == 1) {
                return INT_MIN;
            }
        }

        bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        int64_t a = abs(int64_t(dividend)), b = abs(int64_t(divisor));
        int quotient = 0;

        while (a >= b) {
            int64_t shift = 0;
            while (a >= (b << shift)) {
                ++shift;
            }

            quotient += 1 << (shift - 1);
            a -= b << (shift - 1);
        }

        return sign ? -quotient : quotient;
    }
};

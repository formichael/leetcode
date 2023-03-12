class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;

        int x = 0, y = 1, tmp = 0;
        for (int i = 0; i < n - 1; ++i) {
            tmp = x;
            x = y;
            y += tmp;
        }
        return y;
    }
};

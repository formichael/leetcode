class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0)
            return 1.0;
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n & 1)
            return x * myPow(x, n - 1);
        
        return myPow(x * x, n / 2);
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double ans = 1.0;
        bool neg = n < 0;

        int64_t power = (int64_t)abs(n);
        vector<int64_t> subs;
        int64_t i = 1;

        while (power > 0) {
            if (i > power) {
                power -= i / 2;
                subs.push_back(i / 2);
                i = 1;
            } else if (i == power) {
                power = 0;
                subs.push_back(i);
            } else {
                i *= 2;
            }
        }

        map<int64_t, double> dict;
        dict[1] = x;

        double y = x;
        for (int64_t j = 2; j <= (int64_t)subs[0]; j *= 2) {
            y *= y;
            dict[j] = y;
        }

        for (auto v : subs) {
            ans *= dict[v];
        }

        if (neg) {
            ans = 1 / ans;
        }

        return ans;
    }
};

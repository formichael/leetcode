class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0, num = 1;
        
        for (int i = 1; i <= n; i++) {
            if (i % 5 != 0)
                continue;
                
            num *= i;

            while (num != 0 && num % 5 == 0) {
                fives++;
                num /= 5;
            }

            num = 1;
        }

        return fives;
    }
};

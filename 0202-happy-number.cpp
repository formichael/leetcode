class Solution {
public:
    bool isHappy(int n) {
        set<int> cache;

        while (1) {
            if (auto itr = cache.find(n); itr != cache.end()) // in a cycle
                return false;
            
            if (n == 1)
                return true;

            if (n == 0)
                return false;

            cache.insert(n);

            int tmp = 0;
            while (n > 0) {
                tmp += pow(n % 10, 2);
                n /= 10;
            }
            n = tmp;
        }

        return false; 
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        
        int cntOne = 0;
        while (n > 0) {
            if (n & 0x1) {
                ++cntOne;
            }
            if (cntOne > 1) {
                return false;
            }
            n = n >> 1;
        }

        return cntOne == 1;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

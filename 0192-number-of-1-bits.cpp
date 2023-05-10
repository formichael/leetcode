class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if (n == 0)
                break;

            if ( n & 0x1 )
                ++ans;

            n = (n >> 1);
        }

        return ans;    
    }
};

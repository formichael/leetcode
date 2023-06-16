class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            ans += (n & 0x1) << (31 - i);
            n = (n >> 1);
            if (n == 0)
                break;
        }

        return ans;
    }
};

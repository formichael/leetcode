class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (auto num : nums) {
                if ((num >> i) & 1)
                    sum++;
            }
            ans |= (sum % 3) << i;
        }

        return ans;
    }
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (auto num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

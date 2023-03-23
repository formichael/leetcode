class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += add;
            if (digits[i] < 10) {
                return digits;
            }

            add = digits[i] / 10;
            digits[i] %= 10;
        }

        digits.insert(digits.begin(), add);
        return digits;
    }
};

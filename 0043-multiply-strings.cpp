class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> nums(num1.size() + num2.size());
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                nums[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = nums.size() - 1; i >= 1; --i) {
            if (nums[i] >= 10) {
                nums[i - 1] += nums[i] / 10;
                nums[i] = nums[i] % 10;
            }
        }

        string ans;
        int highestNum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (highestNum == 0 && nums[i] != 0) {
                highestNum = nums[i];
            }

            if (highestNum != 0)
                ans += ((char)nums[i] + '0');
        }

        return ans;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maximum)
                return false;

            maximum = max(maximum, i + nums[i]);
        }

        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[nums.size() - 1];
    }
};

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> out;
        int tmp = 0;

        for (int i = 0; i < nums.size(); ++i) {
            tmp += nums[i];
            out.push_back(tmp);
        }

        return out;
    }
};

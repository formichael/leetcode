class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int valCnt = 0, k = 0;

        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] == val) {
                ++valCnt;
            } else {
                ++k;
                if (valCnt > 0) {
                    nums[idx - valCnt] = nums[idx];
                }
            }
        }

        return k;
    }
};

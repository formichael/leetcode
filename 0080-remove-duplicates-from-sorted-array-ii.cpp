class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = nums.size() > 2 ? 2 : nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[p - 2]) {
                if (i != p) {
                    nums[p] = nums[i];
                }
                p++;
            }
        }
        
        return p;
    }
};

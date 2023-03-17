class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        
        while (cur < nums.size() - 1) {
            int max = nums[cur], next = 0;
            
            for (int i = 1; i <= nums[cur]; ++i) {
                if (cur + i == nums.size() - 1) {
                    next = nums.size() - 1;
                    break;
                }
                
                if (cur + nums[cur + i] + i > max) {
                    max = cur + nums[cur + i] + i;
                    next = cur + i;
                }
            }

            cur = next;
            ans++;
        }

        return ans;
    }
};

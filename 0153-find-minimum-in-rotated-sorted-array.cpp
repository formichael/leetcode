class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size(), low = 0, high = N - 1;

        while (low < high) {
            if (high - low < 2)
                return min(nums[low], nums[high]);

            int mid = low + (high - low) / 2;
            if (nums[low] < nums[mid] && nums[mid] > nums[high]) { // min in right part
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        
        return nums[high];
    }
};

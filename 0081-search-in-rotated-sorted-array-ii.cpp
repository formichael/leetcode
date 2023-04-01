class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target;

        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[low] < nums[mid]) { // left part sorted
                if (target < nums[low] || target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else if (nums[low] > nums[mid]) { // right part sorted
                if (target > nums[high] || target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else { // nums[low] = nums[mid] can't decide which part is sorted
                while (low < nums.size() && nums[low] == nums[mid])
                    ++low;
            }
        }

        return false;
    }
};

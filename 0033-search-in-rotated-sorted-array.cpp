class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        int low = 0, high = nums.size() - 1, mid = 0;

        // finding rotated index
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int pivot = low;
        if (pivot != 0) { // rotated at index: low
            if (nums[0] <= target && target <= nums[pivot - 1]) {
                low = 0;
                high = pivot - 1;
            } else {
                low = pivot;
                high = nums.size() - 1;
            }
        } else {
            low = 0;
            high = nums.size() - 1;
        }

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid = 0;

        while(low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (target > nums[mid] || target < nums[low])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {
                if (target >= nums[low] || target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }
};

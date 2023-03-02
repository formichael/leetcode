class Solution {
public:
    int partion(vector<int>& nums, int low, int high)
    {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot) {
                --high;
            }
            if (low < high) {
                nums[low] = nums[high];
            }

            while ( low < high && nums[low] <= pivot) {
                ++low;
            }
            if (low < high) {
                nums[high] = nums[low];
            }
        }
        nums[low] = pivot;
        return low;
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int i = partion(nums, low, high);
            if (i == k) {
                break;
            } else if (i < k) {
                low = i + 1;
            } else {
                high = i - 1;
            }
        }
        return nums[k];
    }
};

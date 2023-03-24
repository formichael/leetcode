class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() < 2)
            return nums;

        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
 
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> leftSubArray(nums.begin() + start, nums.begin() + mid + 1);
        vector<int> rightSubArray(nums.begin() + mid + 1, nums.begin() + end + 1);
        auto itrLeft = leftSubArray.begin();
        auto itrRight = rightSubArray.begin();
        
        while (itrLeft != leftSubArray.end() && itrRight != rightSubArray.end()) {
            if (*itrLeft < *itrRight) {
                nums[start++] = *itrLeft;
                ++itrLeft;
            }
            else {
                nums[start++] = *itrRight;
                ++itrRight;
            }
        }

        while (itrLeft != leftSubArray.end()) {
            nums[start++] = *itrLeft;
            ++itrLeft;
        }

        while (itrRight != rightSubArray.end()) {
            nums[start++] = *itrRight;
            ++itrRight;
        }
    }
};

class Solution {
public:
    int left = -1, right = -1;

    void doSearchRange(vector<int> &nums, int target, int front, int end)
    {
        while (front <= end) {
            int mid = front + (end - front) / 2;
            if (nums[mid] == target) {
                if (left == -1 || mid < left) {
                    left = mid;
                }
                if (right == -1 || mid > right) {
                    right = mid;
                }

                if (mid > 0)
                    doSearchRange(nums, target, front, mid - 1);
                if (mid < end)
                    doSearchRange(nums, target, mid + 1, end);

                break;
            } else if (nums[mid] < target) {
                front = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        doSearchRange(nums, target, 0, nums.size() - 1);
        return {left, right};
    }
};

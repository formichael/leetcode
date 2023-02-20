class Solution {
public:
    void traceVector(vector<int> const &nums)
    {
        for (auto v : nums) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    void qsort(vector<int>& nums, int L, int R)
    {
        if (L >= R)
            return;

        int left = L, right = R, pivot = nums[L];
        
        while (left < right) {
            if (left < right && nums[right] >= pivot) {
                --right;
            }
            if (left < right) {
                nums[left] = nums[right];
            }

            if (left < right && nums[left] <= pivot) {
                ++left;
            }
            if (left < right) {
                nums[right] = nums[left];
            }

            if (left >= right) {
                nums[left] = pivot;
            }
        }

        qsort(nums, L, right - 1);
        qsort(nums, right + 1, R);
    }

    void sort(vector<int>& nums)
    {
        qsort(nums, 0, nums.size() - 1);
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums);
        traceVector(nums);

        int minDiff = INT_MAX, closetSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                
                if (sum > target) {
                    --k;
                } else {
                    ++j;
                }

                int diff = std::abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    closetSum = sum;
                }
            }
        }

        return closetSum;
    }
};

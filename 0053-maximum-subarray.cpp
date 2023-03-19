class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > max)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideConquer(nums, 0, nums.size() - 1);
    }

    int divideConquer(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return INT_MIN;
        
        int mid = (start + end) / 2;
        int left = divideConquer(nums, start, mid - 1);
        int right = divideConquer(nums, mid + 1, end);

        int sum = 0;
        int leftSuffixMax = 0;
        for (int i = mid - 1; i >= start; --i) {
            sum += nums[i];
            leftSuffixMax = max(leftSuffixMax, sum);
        }

        sum = 0;
        int rightPrefixMax = 0;
        for (int i = mid + 1; i <= end; ++i) {
            sum += nums[i];
            rightPrefixMax = max(rightPrefixMax, sum);
        }

        return max(leftSuffixMax + nums[mid] + rightPrefixMax, max(left, right));
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int start = 0;
        int end = m;

        while(start <= end) {
            int partionA = (start + end) / 2;
            int partionB = (m + n + 1) / 2 - partionA;

            int maxLeftNums1 = partionA == 0 ? INT_MIN : nums1[partionA - 1];
            int minRightNums1 = partionA == m ? INT_MAX : nums1[partionA];

            int maxLeftNums2 = partionB == 0 ? INT_MIN : nums2[partionB - 1];
            int minRightNums2 = partionB == n ? INT_MAX : nums2[partionB];

            if (maxLeftNums1 <= minRightNums2 && maxLeftNums2 <= minRightNums1) {
                if ((m + n) % 2 == 0) {
                    return (std::max(maxLeftNums1, maxLeftNums2) + std::min(minRightNums1, minRightNums2)) / 2.0;
                } else {
                    return std::max(maxLeftNums1, maxLeftNums2);
                }
            } else if (maxLeftNums1 > minRightNums2) {
                end = partionA - 1;
            } else {
                start = partionA + 1;
            }
        }

        return 0;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < leftMax)
                    ans += leftMax - height[left];
                else
                    leftMax = height[left];

                ++left;
            } else {
                if (height[right] < rightMax)
                    ans += rightMax - height[right];
                else
                    rightMax = height[right];
                
                --right;
            }
        }

        return ans;
    }
};

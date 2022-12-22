class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = -1;
        int l = 0;
        int r = height.size() - 1;

        while(l < r) {
            max = std::max(max, std::min(height[l], height[r]) * (r - l));

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max;
    }
};

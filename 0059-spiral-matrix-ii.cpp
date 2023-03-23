class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int val = 0, maxVal = n * n;

        while (left <= right && top <= bottom) {
            // left -> right on top row
            for (int i = left; i <= right; ++i) {
                ans[top][i] = ++val;
            }
            ++top;

            // top -> bottom on right col
            for (int i = top; i <= bottom; ++i) {
                ans[i][right] = ++val;
            }
            --right;

            if (val == maxVal)
                break;

            // right -> left on bottom row
            for (int i = right; i >= left; --i) {
                ans[bottom][i] = ++val;
            }
            --bottom;

            // bottom -> top on left col
            for (int i = bottom; i >= top; --i) {
                ans[i][left] = ++val;
            }
            ++left;
        }

        return ans;
    }
};

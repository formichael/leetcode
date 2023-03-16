class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size() - 1;
        while (left < right) {
            int top = left, bottom = right;
            
            for (int i = 0; i < right - left; ++i) {
                int topLeft = matrix[top][left + i];

                // bottomLeft -> topLeft
                matrix[top][left + i] = matrix[bottom - i][left];

                // bottomRight -> bottomLeft
                matrix[bottom - i][left] = matrix[bottom][right - i];

                // topRight -> bottomRight
                matrix[bottom][right - i] = matrix[top + i][right];

                // topLeft -> topRight
                matrix[top + i][right] = topLeft;
            }

            ++left;
            --right;
        }
    }
};

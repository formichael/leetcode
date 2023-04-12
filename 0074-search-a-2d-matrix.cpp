class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size(), C = matrix[0].size();
        int low = 0, high = R - 1, row = -1, mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[mid][0] == target || matrix[mid][C - 1] == target)
                return true;
            else if (matrix[mid][0] < target && target < matrix[mid][C - 1]) {
                row = mid;
                break;
            } else if (target < matrix[mid][0])
                high = mid -1;
            else if (matrix[mid][C - 1] < target)
                low = mid + 1;
        }

        if (row == -1)
            return false;

        low = 0, high = C - 1;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (target < matrix[row][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
};

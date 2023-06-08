class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = rows * cols;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] < 0)
                    break;
                ans--;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = rows * cols;
        int negCol = cols;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols && col < negCol; col++) {
                if (grid[row][col] < 0) {
                    negCol = min(negCol, col);
                    break;
                }
                ans--;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;

        for (int row = 0; row < rows; row++) {
            int neg = cols, low = 0, high = cols - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (grid[row][mid] < 0) {
                    high = mid - 1;
                    neg = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            ans += (cols - neg);

        }

        return ans;
    }
};

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cols = grid[0].size();
        int ans = 0, minNegCol = cols - 1;

        for (auto &row : grid) {
            while (minNegCol >= 0 && row[minNegCol] < 0) {
                minNegCol--;
            }
            ans += (cols - minNegCol - 1);
        }

        return ans;
    }
};

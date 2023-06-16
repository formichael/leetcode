class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size(), cols = grid[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                bool eq = true;
                for (int i = 0; i < rows; i++) {
                    if (grid[r][i] != grid[i][c]) {
                        eq = false;
                        break;
                    }
                }

                if (eq)
                    ++ans;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int islands = 0;

    map<int, bool> set;
    int rows = 0;
    int cols = 0;

    inline bool visited(int k) {
        auto itr = set.find(k);
        return itr != set.end();
    }

    inline int key(int row, int col) {
        return (row << 16) + col;
    }

    int numIslands(vector<vector<char>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1' && !visited(key(r, c))) {
                    dfs(grid, r, c);
                    ++islands;
                }
            }
        }
        
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row >= rows || row < 0 || col >= cols || col < 0 || grid[row][col] == '0') {
            return;
        }

        int k = key(row, col);
        if (visited(k)) {
            return;
        }

        set[k] = true;

        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
    }
};

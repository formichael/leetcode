class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> cols(n, false);
        vector<bool> slashs(n * 2, false);
        vector<bool> backslashs(n * 2, false);
        vector<vector<bool>> board(n, vector<bool>(n, false));
        dfs(n, 0, ans, cols, slashs, backslashs, board);
        return ans;
    }

    void dfs(int n, int row, int &ans, vector<bool> &cols, vector<bool> &slashs, vector<bool> &backslashs, vector<vector<bool>> &board) {
        if (row == n) {
            ++ans;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int slashIdx = row + col, bsIdx = row - col + n;
            if (cols[col] || slashs[slashIdx] || backslashs[bsIdx])
                continue;

            board[row][col] = true;
            cols[col] = true;
            slashs[slashIdx] = true;
            backslashs[bsIdx] = true;

            dfs(n, row + 1, ans, cols, slashs, backslashs, board);

            board[row][col] = false;
            cols[col] = false;
            slashs[slashIdx] = false;
            backslashs[bsIdx] = false;
        }
    }
};

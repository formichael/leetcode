class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> coles(n, false);
        vector<bool> slashes(n * 2, false);
        vector<bool> backslashes(n * 2, false);
        vector<vector<bool>> board(n, vector<bool>(n, false));
        dfs(n, 0, board, ans, coles, slashes, backslashes);
        return ans;
    }

    void dfs(int n, int row, vector<vector<bool>> &board, vector<vector<string>> &ans, vector<bool> &coles, vector<bool> &slashes, vector<bool> &backslashes) {
        if (row == n) {
            ans.push_back({});
            for (int i = 0; i < n; ++i) {
                string line;
                for (int j = 0; j < n; ++j) {
                    if (board[i][j])
                        line.push_back('Q');
                    else
                        line.push_back('.');
                }
                ans[ans.size() - 1].push_back(line);
            }
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (coles[col] || slashes[row - col + n] || backslashes[row + col])
                continue;

            board[row][col] = true;
            coles[col] = true;
            slashes[row - col + n] = true;
            backslashes[row + col] = true;

            dfs(n, row + 1, board, ans, coles, slashes, backslashes);

            board[row][col] = false;
            coles[col] = false;
            slashes[row - col + n] = false;
            backslashes[row + col] = false;
        }
    }
};

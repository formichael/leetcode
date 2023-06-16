class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();

        // turn the unsurrounded O -> T
        for (int c = 0; c < COLS; c++) {
            dfs(board, 0, c);
            dfs(board, ROWS - 1, c);
        }
        for (int r = 1; r < ROWS - 1; r++) {
            dfs(board, r, 0);
            dfs(board, r, COLS - 1);
        }

        // flip the surrounded O -> X
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }

        // revert all the T -> O
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'T')
                    board[r][c] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        int ROWS = board.size(), COLS = board[0].size();
        if (r < 0 || r == ROWS || c < 0 || c == COLS || board[r][c] != 'O')
            return;
        
        board[r][c] = 'T';

        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
    }
};

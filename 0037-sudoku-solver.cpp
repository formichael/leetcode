class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        doSolveSudoku(board, 0, 0);
    }

    bool doSolveSudoku(vector<vector<char>>& board, int row, int col)
    {
        if (col == 9) {
            row += 1;
            col = 0;
        }

        if (row == 9) {
            return true;
        }

        if (board[row][col] != '.')
            return doSolveSudoku(board, row, col + 1);

        for (char c = '1'; c <= '9'; ++c) {
            if (!validSudoku(board, row, col, c))
                continue;
            
            board[row][col] = c;

            if (doSolveSudoku(board, row, col + 1))
                return true;

            board[row][col] = '.';
        }

        return false;
    }

    bool validSudoku(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) 
                return false;
            if (board[i][col] == c)
                return false;
        }

        int rowSub = (row / 3) * 3;
        int colSub = (col / 3) * 3;
        for (int i = rowSub; i < rowSub + 3; ++i) {
            for (int j = colSub; j < colSub + 3; ++j) {
                if (board[i][j] == c)
                    return false;
            }
        }

        return true;
    }
};

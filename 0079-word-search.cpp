class Solution {
public:
    const int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (dfs(board, word, row, col, visited, 0))
                    return true;
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, vector<vector<bool>> &visited, int wordIdx) {
        if (wordIdx == word.size()) {
            return true;
        }

        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;

        if (board[row][col] != word[wordIdx])
            return false;

        if (visited[row][col])
            return false;

        visited[row][col] = true;
        for (auto &d : dir) {
            if (dfs(board, word, row+d[0], col+d[1], visited, wordIdx+1))
                return true;
        }
        visited[row][col] = false;

        return false;
    }
};

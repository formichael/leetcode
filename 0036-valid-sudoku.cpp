class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> set;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                string s(1, board[i][j]);
                if (!set.insert(s + "@row" + to_string(i)).second ||
                    !set.insert(s + "@col" + to_string(j)).second ||
                    !set.insert(s + "@box" + to_string(i/3) + to_string(j/3)).second) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkUpdateDict(const char c, map<char, bool> &d)
    {
        if (c == '.') {
            return true;
        }
        auto itr = d.find(c);
        if (itr != d.end()) {
            return false;
        }
        d[c] = true;
        return true;
    }

    bool check3x3(vector<vector<char>> &board, int m, int n){
        map<char, bool> d, d2;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!checkUpdateDict(board[i+m][j+n], d)) {
                    return false;
                }
                if (!checkUpdateDict(board[j+m][i+n], d2)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows or cloumns which length is 9
        map<char, bool> d, d2;
        for (int i = 0; i < 9; ++i) {
            d.clear();
            d2.clear();
            for (int j = 0; j < 9; ++j) {
                if (!checkUpdateDict(board[i][j], d)) {
                    return false;
                }
                if (!checkUpdateDict(board[j][i], d2)) {
                    return false;
                }
            }
        }

        // check 3 * 3 boards
        for (int m = 0; m <= 6; m += 3) {
            for (int n = 0; n <= 6; n += 3) {
                if (!check3x3(board, m , n)) {
                    return false;
                }
            }
        }

        return true;
    }
};

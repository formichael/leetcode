class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zeroRows;
        set<int> zeroCols;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        for (auto row : zeroRows) {
            for (int col = 0; col < matrix[0].size(); col++)
                matrix[row][col] = 0;
        }

        for (auto col : zeroCols) {
            for (int row = 0; row < matrix.size(); row++)
                matrix[row][col] = 0;
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        bool firstColZero = false;

        // flag first row|col cell for deciding row|col has zero
        for (int i = 0; i < M; i++) {
            if (matrix[i][0] == 0)
                firstColZero = true;

            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // fill zeros exclue first row and first column
        for (int row = 1; row < M; row++) {
            for (int col = 1; col < N; col++) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;
            }
        }

        // fill zeros for first row
        for (int col = 0; col < N; col++) {
            if (matrix[0][0] == 0)
                matrix[0][col] = 0;
        }

        // fill zeros for first col
        for (int row = 0; row < M; row++) {
            if (firstColZero)
                matrix[row][0] = 0;
        }
    }
};

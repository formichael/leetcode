class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }

        int row = 0;
        std::string ss[numRows];
        bool down = false;

        for (int idx = 0; idx < s.size(); ++idx) {
            ss[row].push_back(s[idx]);

            if (row == 0) {
                down = true;
            } else if (row == numRows - 1) {
                down = false;
            }

            down ? ++row : --row;
        }

        std::string out;

        for (int row = 0; row < numRows; ++row) {
            out += ss[row];
        }

        return out;
    }
};

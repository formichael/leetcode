class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<int> set;

        while (columnNumber > 0) {
            int remainder = columnNumber % 26;
            set.push_back(remainder == 0 ? 26 : remainder);

            if (remainder == 0)
                columnNumber -= 26;

            columnNumber /= 26;
        }

        string ans;
        for (int i = set.size() - 1; i >= 0; i--) {
            char c = set[i];
            ans.push_back('A' + c - 1);
        }

        return ans;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int left = -1, right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (right == 0 && s[i] != ' ') {
                right = i;
                continue;
            }

            if (right != 0 && s[i] == ' ') {
                left = i;
                break;
            }
        }
        return right - left;
    }
};

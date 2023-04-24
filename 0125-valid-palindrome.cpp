class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            while (left < s.size() && !isAlphanumberic(s[left]))
                left++;
            while (right >= 0 && !isAlphanumberic(s[right]))
                right--;

            if (left > right || left >= s.size() || right < 0)
                return true;

            if (toLower(s[left]) != toLower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }

    bool isAlphanumberic(char c) {
        return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }

    char toLower(char c) {
        if ('A' <= c && c <= 'Z')
            return c + ('a' - 'A');
        return c;
    }
};

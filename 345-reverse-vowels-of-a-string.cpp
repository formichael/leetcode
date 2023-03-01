class Solution {
public:
    inline bool isVowels(const char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        bool ivLeft = false, ivRight = false;
        
        while (left < right) {
            ivLeft = isVowels(s[left]);
            ivRight = isVowels(s[right]);

            if (ivLeft && ivRight) {
                if (s[left] != s[right]) {
                    char c = s[left];
                    s[left] = s[right];
                    s[right] = c;
                }
                ++left;
                --right;
            }
            
            if (!ivLeft) {
                ++left;
            }
            if (!ivRight) {
                --right;
            }
        }

        return s;
    }
};

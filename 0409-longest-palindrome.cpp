class Solution {
public:
    int longestPalindrome(string s) {
        constexpr int len = 52;
        int arr[len] = {0};
        for (char c : s) {
            if (c < 91) // a ~ z
                arr[c-65] += 1;
            else        // A ~ Z
                arr[c-71] += 1;
        }

        int longestLen = 0;
        bool hasOddLetter = false;

        for (int i = 0; i < len; ++i) { 
            if (arr[i] == 0) {
                continue;
            }

            if (arr[i] % 2 != 0) { // odd count letters
                longestLen += arr[i] - 1;
                if (!hasOddLetter) {
                    hasOddLetter = true;
                }
            } else { // even count letters
                longestLen += arr[i];
            }
        }

        return longestLen + hasOddLetter;
    }
};

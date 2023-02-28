class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();
        if (haystack.size() < nsize) {
            return -1;
        }

        bool cmp = false;
        
        for (int i = 0; i < haystack.size() - nsize + 1; ++i) {
            cmp = true;

            for (int j = 0; j < nsize; ++j) {
                if (haystack[i + j] != needle[j]) {
                    cmp = false;
                    break;
                }
            }

            if (cmp) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) {
            return 1;
        }
        
        int maxSubLen = 0;
        std::map<char, char> dict;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                auto itr = dict.find(s[j]);
                if (itr != dict.end()) {
                    if (dict.size() > maxSubLen) {
                        maxSubLen = dict.size();
                    }
                    dict.clear();
                    break;
                }
                
                dict[s[j]] = 1;
            }
        }
        
        return maxSubLen;
    }
};

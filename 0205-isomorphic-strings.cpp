class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> dict;
        map<char, char> rev;
        
        for (int i = 0; i < s.size(); ++i) {
            if (auto itr = dict.find(s[i]); itr != dict.end()) {
                if (t[i] != itr->second) {
                    return false;
                }
            }
            else if (auto itr2 = rev.find(t[i]); itr2 != rev.end()) {
                if (s[i] != itr2->second) {
                    return false;
                }
            } 
            else {
                dict[s[i]] = t[i];
                rev[t[i]] = s[i];
            }
        }

        return true;
    }
};

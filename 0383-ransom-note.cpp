class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cache[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            cache[magazine[i] - 'a']++;
        }   
        for (int i = 0; i < ransomNote.size(); i++) {
            if (--cache[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};

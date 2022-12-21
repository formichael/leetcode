class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<string, int> one = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
        map<string, int> two = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

        int total = s.size();
        if (total == 0) {
            return result;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 == total) {
                result += one[string(1, s[i])];
            }
            else {
                string st = string(1, s[i]) + string(1, s[i+1]);
                if (two.find(st) == two.end()) {
                    result += one[string(1, s[i])];
                }
                else {
                    result += two[st];
                    i++;
                }
            }
        }
        return result;
    }
};

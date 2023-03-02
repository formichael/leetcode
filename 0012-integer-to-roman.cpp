class Solution {
public:
    string intToRoman(int num) {
        string s = ""; 
        map<int, string, greater<int>> kvs = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for (auto& kv : kvs) {
            if (num <= 0) {
                break;
            }   
            if (num >= kv.first) {
                int repeat = int(num/kv.first);
                for (int j = 0; j < repeat; j++) {
                    s += string(kvs[kv.first]);
                }   
            }   
            num %= kv.first;
        }   
        return s;
    }
};

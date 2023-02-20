class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> out;
        if (digits.size() == 0) {
            return out;
        }

        std::map<char, std::vector<std::string>> dict = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}},
        };
        
        out = dict[digits[0]];
        if (digits.size() == 1) {
            return out;
        }

        std::vector<std::string> tmp;
        for (int i = 1; i < digits.size(); ++i) {
            tmp.clear();
            for (int j = 0; j < out.size(); ++j) {
                auto d = dict[digits[i]];
                for (int k = 0; k < d.size(); ++k) {
                    tmp.push_back(out[j] + d[k]);
                }
            }
            out = tmp;
        }

        return out;
    }
};

class Solution {
public:
    static bool compare(int a, int b) { 
        string s = to_string(a);
        string s2 = to_string(b);
        auto str = s + s2;
        auto str2 = s2 + s;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] > str2[i]) {
                return true;
            } else if (str[i] < str2[i]) {
                return false;
            }
        }
        return false;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        stringstream ss;
        for (auto num : nums) {
            ss << to_string(num);
        }
        auto answer = ss.str();
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] != '0') {
                return answer.substr(i);
            }
        }
        return "0";
    }
};

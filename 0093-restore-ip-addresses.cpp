class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};

        vector<string> ans;
        vector<uint8_t> ip;

        helper(s, ip, ans);
        
        return ans;
    }

    void helper(string s, vector<uint8_t> &ip, vector<string> &ans) {
        if (s == "") {
            if (ip.size() == 4) {
                string tmp;
                for (int i = 0; i <= 3; ++i) {
                    tmp.append(to_string(ip[i]));
                    if (i < 3)
                        tmp.append(".");
                }
                ans.push_back(tmp);
            }
            return;
        }

        if (ip.size() >= 4)
            return;

        for (int i = 1; i <= 3; ++i) {
            if (s.size() < i)
                break;
            
            if (i > 1 && s[0] == '0')
                continue;

            int j = stoi(s.substr(0, i));
            if (j > 255)
                continue;

            ip.push_back(j);
            helper(s.substr(i), ip, ans);
            ip.pop_back();
        }
    }
};

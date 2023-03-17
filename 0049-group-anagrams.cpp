class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> dict;
        for (auto &str : strs) {
            string k = str;
            sort(k.begin(), k.end());
            dict[k].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &e : dict) {
            ans.push_back(e.second);
        }

        return ans;
    }
};

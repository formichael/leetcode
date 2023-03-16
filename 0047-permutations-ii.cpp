class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int8_t> dict;
        for (auto num : nums) {
            dict[num]++;
        }

        vector<int> elem;
        perm(nums, elem, dict);
        return ans;
    }

    void perm(vector<int>& nums, vector<int> &elem, map<int, int8_t> &dict) {
        if (elem.size() == nums.size()) {
            ans.push_back(elem);
            return;
        }

        for (auto itr = dict.begin(); itr != dict.end(); ++itr) {
            if (itr->second == 0) {
                continue;
            }

            elem.push_back(itr->first);
            itr->second--;

            perm(nums, elem, dict);

            elem.pop_back();
            itr->second++;
        }
    }
};

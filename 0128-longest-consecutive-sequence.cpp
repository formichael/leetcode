class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num : nums)
            set.insert(num);

        int ans = 0, tmp = 0, right = 0;

        for (auto num : nums) {
            // num has left neighbor, so it's not the start of the consecutive sequence
            // no need to count from it
            if (set.find(num - 1) != set.end()) {
                continue;
            }

            // num is the start of the consecutive sequence
            tmp = 1;
            right = num;

            while (set.find(++right) != set.end()) {
                tmp++;
            }

            ans = std::max(ans, tmp);
        }

        return ans;
    }
};

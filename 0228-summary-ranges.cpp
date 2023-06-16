class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int N = nums.size();

        if (N == 0) {
            return ans;
        }

        int lastIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (lastIdx == -1) {
                lastIdx = i;
                continue;
            }

            if (i > 0 && nums[i] > nums[i - 1] + 1) {
                if (nums[lastIdx] == nums[i - 1]) {
                    ans.push_back(to_string(nums[lastIdx]));
                }
                else {
                    ostringstream out;
                    out << nums[lastIdx] << "->" << nums[i - 1];
                    ans.push_back(out.str());
                }

                lastIdx = i;
            }
        }

        if (lastIdx < N - 1) {
            ostringstream out;
            out << nums[lastIdx] << "->" << nums[N - 1];
            ans.push_back(out.str());
        }
        else {
            ans.push_back(to_string(nums[N - 1]));
        }

        return ans;
    }
};

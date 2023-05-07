class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> times;
        int N = nums.size() / 2;
        for (auto num : nums) {
            times[num]++;
            if (times[num] > N)
                return num;
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for (auto num : nums) {
            if (count == 0) {
                ans = num;
            }
            count += num == ans ? 1 : -1;
        }
        return ans;
    }
}

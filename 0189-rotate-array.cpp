class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k %= N;

        stack<int> stk;
        for (int i = 0; i < k; i++) {
            stk.push(nums[N - i - 1]);
        }

        for (int i = N - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        for (int i = 0; i < k; i++) {
            int v = stk.top();
            stk.pop();
            nums[i] = v;
        }
    }
};

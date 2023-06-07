class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> l2r(N, 1);
        vector<int> r2l(N, 1);
        vector<int> ans(N, 1);

        for (int i = 1; i < N; i++) {
            l2r[i] = l2r[i - 1] * nums[i - 1];
        }

        for (int i = N - 2; i >= 0; i--) {
            r2l[i] = r2l[ i + 1] * nums[ i + 1];
        }

        for (int i = 0; i < N; i++) {
            ans[i] = l2r[i] * r2l[i];
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 1);

        for (int i = 1; i < N; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int product = 1;
        for (int i = N - 1; i >= 0; i--) {
            ans[i] *= product;
            product *= nums[i];
        }

        return ans;
    }
};

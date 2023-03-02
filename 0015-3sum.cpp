Solution {
public:
    void qsort(vector<int>& a, int L, int R)
    {
        if (L >= R)
            return;

        int left = L, right = R, pivot = a[L];

        while (left < right) {
            while (left < right && a[right] >= pivot) {
                --right;
            }
            if (left < right) {
                a[left] = a[right];
            }

            while (left < right && a[left] <= pivot) {
                ++left;
            }
            if (left < right) {
                a[right] = a[left];
            }

            if (left >= right) {
                a[left] = pivot;
            }
        }

        qsort(a, L, right - 1);
        qsort(a, right + 1, R);
    }

    void sort(vector<int>& nums)
    {
        if (nums.size() < 2)
            return;

        qsort(nums, 0, nums.size() - 1); 
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        if (nums.size() < 3)
            return out;

        sort(nums);

        int a = -100001, b = 0, c = 0, left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (a == nums[i])
                continue;

            a = nums[i];
            left = i + 1;
            right = nums.size() - 1;

            while (left < right) {
                if (a + nums[left] + nums[right] > 0) {
                    --right;
                } else if (a + nums[left] + nums[right] < 0) {
                    ++left;
                } else {
                    b = nums[left];
                    c = nums[right];
                    out.push_back({a, b, c});

                    while (nums[++left] == b && left < right) {}
                    while (nums[--right] == c && left < right) {}
                }
            }
        }  

        return out;    
    }
};

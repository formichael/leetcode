class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int L = cost.size();
        vector<int> cache(L, 0);
        
        for (int idx = L - 1; idx >= 0; --idx) {
            if (idx == L - 1 || idx == L - 2) {
                cache[idx] = cost[idx];
            } else {
                cache[idx] = cost[idx] + min(cache[idx + 1], cache[idx + 2]);
            }
        }

        return min(cache[0], cache[1]);
    }
};

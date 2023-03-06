class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, lowest = prices[0], tmp = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            } else if (prices[i] > lowest){
                tmp = prices[i] - lowest;
                if (tmp > profit) {
                    profit = tmp;
                }
            }
        }
        return profit;
    }
};

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector<bool> ans(candies.size(), false);

        // find kids' most candies (without extraCandies)
        for (auto i : candies) {
            if (i > max)
                max = i;
        }


        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max)
                ans[i] = true;
        }

        return ans;
    }
};

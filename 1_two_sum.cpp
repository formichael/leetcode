class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vhelp;
        vector<int> vres;
        vector<int>::iterator it;
        int i = 0;
        for(it = nums.begin(); it != nums.end(); it++)
        {
            if(!vhelp.empty())
            {
                for(int j = 0; j < vhelp.size(); j++)
                {
                    if(*it + vhelp[j] == target)
                    {
                        vres.push_back(j);
                        vres.push_back(i);
                        return vres;
                    }
                }
                vhelp.push_back(*it);
            }
            else
            {
                vhelp.push_back(*it);
            }
            i++;
        }
        return vres;
    }
};

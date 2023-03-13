class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        const int L = p.size();
        constexpr int letterCnt = 26;
        int cnts[letterCnt] = {0};
        
        for (int i = 0; i < L; ++i) {
            cnts[p[i] - 'a'] += 1;
        }

        int cmpCnts[letterCnt] = {0};
        int left = 0, right = 0;

        while (right < s.size()) {
            if (cnts[s[right] - 'a'] != 0) {
                cmpCnts[s[right] - 'a']++;
            }

            if (right - left + 1 == L) {
                if ( equal(begin(cmpCnts), end(cmpCnts), begin(cnts)) )
                    ans.push_back(left);

                if (cmpCnts[s[left] - 'a'] > 0)
                    cmpCnts[s[left] - 'a']--;
                
                left++;
            }

            right++;
        }

        return ans;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int add = 0;
        auto itrA = a.rbegin();
        auto itrB = b.rbegin();

        while (itrA != a.rend() || itrB != b.rend()) {
            int bit = add;

            if (itrA != a.rend()) {
                bit += *itrA - '0';
                ++itrA;
            }
                
            if (itrB != b.rend()) {
                bit += *itrB - '0';
                ++itrB;
            }

            if (bit < 2) {
                ans.push_back(bit + '0');
                add = 0;
            } else {
                ans.push_back('0' + (bit - 2));
                add = 1;
            }
        }

        if (add)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

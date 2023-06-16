class Solution {
public:
    int firstUniqChar(string s) {
        int N = s.size();
        array<int, 26> debut;
        debut.fill(-1);

        for (int i = 0; i < N; i++) {
            int c = s[i] - 'a';
            if (debut[c] == -1)
                debut[c] = i;
            else if (debut[c] == N)
                continue;
            else
                debut[c] = N;
        }

        int ans = -1;
        for (int i = 0; i < 26; i++) {
            if (debut[i] == -1 || debut[i] == N)
                continue;
            
            if (ans == -1 || debut[i] < ans)
                ans = debut[i];
        }

        return ans;
    }
};

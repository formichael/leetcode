class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int N = citations.size();

        for (int i = 0; i < N; i++) {
            if (N - i <= citations[i])
                return N - i;
        }

        return 0;
    }
};

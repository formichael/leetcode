class Solution {
public:
    struct kv {
        kv(string _k, int _v) : k(_k), v(_v) {}

        string k;
        int v = 0;
    };

    class cmp {
    public:
        bool operator() (kv &a, kv &b) {
            return a.v == b.v ? a.k > b.k : a.v < b.v;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> dict;
        for (auto &word : words) {
            dict[word]++;
        }

        priority_queue<kv, vector<kv>, cmp> pq; 

        for (auto &d : dict) {
            pq.push(kv(d.first, d.second));
        }

        vector<string> ans;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            auto &elem = pq.top();
            ans.push_back(elem.k);
            pq.pop();
        }

        return ans;
    }
};

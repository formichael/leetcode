class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto v : stones) {
            pq.push(v);
        }

        while (pq.size() > 1) {
            int weight = pq.top();
            pq.pop();

            int weight2 = pq.top();
            pq.pop();

            if (weight > weight2) {
                pq.push(weight - weight2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

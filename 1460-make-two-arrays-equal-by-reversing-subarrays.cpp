class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::map<int, int> m;

        for (auto v : target) {
            m[v] += 1;
        }

        for (auto v : arr) {
            auto itr = m.find(v);
            if (itr == m.end() || itr->second == 0) {
                return false;
            }
            itr->second--;
        }

        return true;
    }
};

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < target.size(); i++) {
            if (target[i] != arr[i]) {
                return false;
            }
        }

        return true;
    }
};

class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (auto itr = val2idx.find(val); itr != val2idx.end()) {
            return false;
        }

        vals.push_back(val);
        val2idx[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto itr = val2idx.find(val);
        if (itr == val2idx.end()) {
            return false;
        }

        int idx = itr->second, lastIdx = vals.size() - 1;
        if (idx != lastIdx) {
            vals[idx] = vals[lastIdx];
            if (auto itr2 = val2idx.find(vals[lastIdx]); itr != val2idx.end()) {
                itr2->second = idx;
            }
        }
        vals.pop_back();

        val2idx.erase(itr);
        return true;
    }
    
    int getRandom() {
        int r = std::rand() % vals.size();
        return vals[r];
    }

private:
    map<int, int> val2idx;
    vector<int> vals;
};

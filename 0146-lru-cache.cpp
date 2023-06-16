class LRUCache {
struct Node {
    int key = 0;
    int value = 0;
    Node(int k, int v) : key(k), value(v) {}
};
private:
    const int _capacity = 0;
    list<Node> cache;
    unordered_map<int, list<Node>::iterator> data;
public:
    LRUCache(int capacity) : _capacity(capacity) {
    }
    
    int get(int key) {
        auto itr = data.find(key);
        if (itr == data.end())
            return -1;

        const auto &listItr = itr->second;
        cache.splice(begin(cache), cache, listItr);
        return listItr->value;
    }
    
    void put(int key, int value) {
        auto itr = data.find(key);
        if (itr != data.end()) {
            const auto &listItr = itr->second;
            cache.splice(begin(cache), cache, listItr);
            listItr->value = value;
            return;
        }

        if (cache.size() == _capacity) {
            auto b = cache.back();
            data.erase(b.key);
            cache.pop_back();
        }

        cache.emplace_front(Node(key, value));
        data[key] = begin(cache);
    }
};

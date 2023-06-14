// DFS hashmap

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> old2new;
        return dfs(node, old2new);
    }

    Node* dfs(Node* node, map<Node*, Node*> &old2new) {
        if (!node)
            return nullptr;

        auto itr = old2new.find(node);
        if (itr != old2new.end()) {
            return old2new[node];
        }

        Node *copy = new Node(node->val);
        old2new[node] = copy;

        for (auto &nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, old2new));
        }

        return copy;
    }    
};

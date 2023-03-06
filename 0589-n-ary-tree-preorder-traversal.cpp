class Solution {
public:
    void doPreorder(Node* root, vector<int> &out) {
        if (!root)
            return ;

        out.push_back(root->val);
        
        for (auto node : root->children) {
            if (node)
                doPreorder(node, out);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> out;
        doPreorder(root, out);
        return out;
    }
};

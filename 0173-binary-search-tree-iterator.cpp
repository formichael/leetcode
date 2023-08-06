class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        helper(root, nodes);
    }

    void helper(TreeNode* root, vector<TreeNode*> &nodes) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            helper(root->left, nodes);
        }

        nodes.push_back(root);
        
        if (root->right) {
            helper(root->right, nodes);
        }
    }
    
    int next() {
        ++cur;
        assert(cur < nodes.size());
        return nodes[cur]->val;
    }
    
    bool hasNext() {
        return cur + 1 < nodes.size();
    }

private:
    int cur = -1;
    vector<TreeNode*> nodes;
};

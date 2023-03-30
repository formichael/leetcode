class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode *first = nullptr, *second = nullptr;
        inorderTree(root, pre, first, second);

        if (!first || !second)
            return;

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    void inorderTree(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &second) {
        if (!root)
            return;

        inorderTree(root->left, pre, first, second);

        if (!first && pre->val > root->val)
            first = pre;

        if (first && pre->val > root->val)
            second = root;
        
        pre = root;

        inorderTree(root->right, pre, first, second);
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);  
        root->right = invertTree(tmp);

        return root;
    }
};

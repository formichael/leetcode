class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;

        TreeNode* tmp = root->right;
        if (tmp)
            flatten(tmp);

        if (!root->left)
            return;
 
        TreeNode* left = root->left;
        root->left = nullptr;
        root->right = left;
        
        flatten(left);

        TreeNode* right = root->right;
        while(right && right->right) {
            right = right->right;
        }

        if (right)
            right->right = tmp;
    }
};

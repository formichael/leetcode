class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int leftH = root->left ? height(root->left) : 0;
        int rightH = root->right ? height(root->right) : 0;
        if ( abs(leftH - rightH) > 1 )
            return false;

        return isBalanced(root->left) && isBalanced(root->right);    
    }

    int height(TreeNode* root) {
        if (!root)
            return 0;
        
        return max(height(root->left), height(root->right)) + 1;
    }
};

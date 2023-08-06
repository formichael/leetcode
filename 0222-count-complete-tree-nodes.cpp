class Solution {
public:
    int countNodes(TreeNode* root) {
        int height = 0;
        TreeNode* left = root;
        while (left) {
            ++height;
            left = left->left;
        }

        int rightHeight = 0;
        TreeNode* right = root;
        while (right) {
            ++rightHeight;
            right = right->right;
        }

        if (height == rightHeight) {
            return (1 << height) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


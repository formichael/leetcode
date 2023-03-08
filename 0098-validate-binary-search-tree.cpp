class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
    }

    bool valid(TreeNode *root, int64_t min, int64_t max)
    {
        if (!root)
            return true;
        int64_t val = (int64_t)(root->val);
        if (val <= min || val >= max)
            return false;
        return valid(root->left, min, val) &&
               valid(root->right, val, max);
    }
};
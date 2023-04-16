/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preStop, int inStart, int inStop) {
        if (preStart > preStop)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int mid = 0;
        for (mid = inStart; mid <= inStop; mid++) {
            if (inorder[mid] == root->val)
                break;
        }

        int leftLen = mid - inStart;
        root->left = helper(preorder, inorder, preStart + 1, preStart + leftLen, inStart, mid - 1);

        root->right = helper(preorder, inorder, preStart + leftLen + 1, preStop, mid + 1, inStop);

        return root;
    }
};

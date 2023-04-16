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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inStop, int postStart, int postStop) {
        if (postStart > postStop)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postStop]);

        int mid = 0;
        for (mid = inStart; mid <= inStop; mid++) {
            if (inorder[mid] == root->val)
                break;
        }

        int leftLen = mid - inStart;
        root->left = helper(inorder, postorder, inStart, mid - 1, postStart, postStart + leftLen - 1);
        root->right = helper(inorder, postorder, mid + 1, inStop, postStart + leftLen, postStop - 1);

        return root;
    }
};

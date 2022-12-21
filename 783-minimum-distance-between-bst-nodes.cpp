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
    
    int prev = -1, curr = -1;
    int min = INT_MAX;
    
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left);
        
        if(prev == -1) {
            prev = root->val;
        } else if(curr == -1) {
            curr = root->val;
        }
        
        if(prev != -1 && curr != -1) {
            min = std::min(curr - prev, min);
            
            prev = curr;
            curr = -1;
        }
        
        inorder(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return min;
    }
};

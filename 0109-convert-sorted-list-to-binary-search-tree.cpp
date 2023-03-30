class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        vector<int> nums;

        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }

        return makeTree(nums, 0, nums.size() - 1);
    }

    TreeNode* makeTree(vector<int> &nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = makeTree(nums, left, mid - 1);
        root->right = makeTree(nums, mid + 1, right);

        return root;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode *slow = head, *fast = head, *pre = nullptr;
        while (slow && fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        
        if (pre)
            pre->next = nullptr;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;    
    }
};

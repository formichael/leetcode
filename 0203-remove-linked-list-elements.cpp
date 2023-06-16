class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = head, *pre = dummy;

        while (cur) {
            if (cur->val != val) {
                pre->next = cur;
                pre = cur;
            }
            
            cur = cur->next;
        }

        pre->next = nullptr;
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        head = dummy;

        ListNode *cur = head, *tmp = nullptr;

        while (cur) {
            tmp = cur->next;
            cur->next = nullptr;

            ListNode *subCur = head, *pre = nullptr;
            while (subCur) {
                if (subCur->val > cur->val)
                    break;
                pre = subCur;
                subCur = subCur->next;
            }

            if (pre)
                pre->next = cur;
            cur->next = subCur;

            cur = tmp;
        }
        
        return head->next;
    }
};

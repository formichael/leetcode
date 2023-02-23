class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int seq = 0;
        ListNode *pre = NULL, *cur = head, *ppre = NULL, *tmp = NULL;

        while (cur) {
            ++seq;
            tmp = cur -> next;

            if (seq % 2 == 0) {
                cur -> next = pre;
                pre -> next = tmp;
                if (ppre) {
                    ppre->next = cur;
                }

                if (seq == 2) {
                    head = cur;
                }
                
                ppre = cur;
            } else {
                ppre = pre;
                pre = cur;
            }

            cur = tmp;
        }

        return head;
    }
};

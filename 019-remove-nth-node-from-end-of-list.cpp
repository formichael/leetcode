class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *pre = NULL, *cur = head, *tmp = NULL;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revHead = reverseList(head);
        ListNode* cur = revHead, *pre = NULL;
        int i = 0;

        while (cur) {
            if (++i == n) {
                if (!pre) {
                    revHead = cur->next;
                } else {
                    pre->next = cur->next;
                }
                break;
            }

            pre = cur;
            cur = cur->next;
        }

        return reverseList(revHead);
    }
};

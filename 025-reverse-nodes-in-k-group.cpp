class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode *end)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *pre = nullptr, *cur = head, *tmp = nullptr;
        while (cur && cur != end) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head, *rhead = nullptr, *tmp = nullptr, *front = nullptr, *pre = nullptr;
        int i = 0;

        while (cur) {
            if (front == nullptr) {
                front = cur;
            }

            if (++i < k) {
                cur = cur->next;
                continue;
            }

            // i == k
            tmp = cur->next;

            ListNode *head2 = reverseList(front, cur->next);
            if (!rhead && head2) {
                rhead = head2;
            }

            if (pre) {
                pre->next = head2;
            }
            
            pre = front;
            cur = tmp;

            // reset range idx and pointers
            i = 0;
            front = nullptr;
        }

        if (front && pre) {
            pre->next = front;
        }

        return rhead;
    }
};

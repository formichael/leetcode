class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr)
            return head;

        int len = 0;
        ListNode *node = head;
        while (node) {
            ++len;
            node = node->next;
        }

        k %= len;
        for (int i = 0; i < k; ++i) {
            ListNode *cur = head, *pre = nullptr;
            while (cur->next) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = nullptr;
            cur->next = head;
            head = cur;
        }

        return head;
    }
};

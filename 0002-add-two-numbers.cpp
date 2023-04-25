class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;

        ListNode *c1 = l1, *c2 = l2, *cur = nullptr;
        int8_t carry = 0;

        while (c1 && c2) {
            int8_t sum = c1->val + c2->val + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            
            if (!head) {
                head = node;
            } else {
                cur->next = node;
                cur = node;
            }

            cur = node;
            c1 = c1->next;
            c2 = c2->next;
        }

        while (c1) {
            int8_t sum = c1->val + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            
            if (!head) {
                head = node;
            } else {
                cur->next = node;
                cur = node;
            }

            cur = node;
            c1 = c1->next;
        }

        while (c2) {
            int8_t sum = c2->val + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            
            if (!head) {
                head = node;
            } else {
                cur->next = node;
                cur = node;
            }

            cur = node;
            c2 = c2->next;
        }

        if (carry)
            cur->next = new ListNode(carry);

        return head;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *out = NULL, *cur = NULL;
        while(1) {
            if (!list1 && !list2)
                return out;

            if (!list2 || (list1 && list1->val <= list2->val)) {
                ListNode *node = new(ListNode);
                node->val = list1->val;
                node->next = nullptr;

                if (out == NULL) {
                    out = node;
                } else {
                    cur->next = node;
                }
                cur = node;
                list1 = list1->next;
            }
            else if (!list1 || (list2 && list2->val <= list1->val)) {
                ListNode *node = new(ListNode);
                node->val = list2->val;
                node->next = nullptr;

                if (out == NULL) {
                    out = node;
                } else {
                    cur->next = node;
                }
                cur = node;
                list2 = list2->next;
            }
        }

        return out;
    }
};

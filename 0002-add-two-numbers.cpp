class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = NULL;
        ListNode* l3 = NULL;
        int r = 0;
        
        for(;;) {
            int t = r;
            r = 0;
            if (l1 == NULL && l2 == NULL && t == 0) {
                break;
            }
            if (l1 != NULL) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                t += l2->val;
                l2 = l2 -> next;
            }
            if (t > 9) {
                r += 1;
                t -= 10;
            }
            
            ListNode* l4 = new ListNode(t);
            if (l3 == NULL) {
                l3 = l4;
                l = l3;
            } else {
                l3->next = l4;
                l3 = l3->next;
            }
        }
        
        return l;
    }
};

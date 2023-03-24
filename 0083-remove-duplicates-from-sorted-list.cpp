/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        int val = head->val - 1;
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            if (cur->val != val) {
                if (pre)
                    pre->next = cur;
                
                pre = cur;
                val = cur->val;
            }
            cur = cur->next;
        }
        
        if (pre)
            pre->next = nullptr;

        return head;
    }
};

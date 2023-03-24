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
        map<int, int> dict;
        ListNode *cur = head;
        while (cur) {
            dict[cur->val]++;
            cur = cur->next;
        }

        cur = head;
        head = nullptr;
        ListNode *pre = nullptr;

        while (cur) {
            if (dict[cur->val] == 1) {
                if (head == nullptr)
                    head = cur;

                if (pre)
                    pre->next = cur;

                pre = cur;
            }

            cur = cur->next;
        }

        if (pre)
            pre->next = nullptr;

        return head;
    }
};

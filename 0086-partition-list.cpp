// TODO two pointers version, O(1) space complexity

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
    ListNode* partition(ListNode* head, int x) {
        queue<int> lt, ge;
        ListNode* cur = head;

        while (cur) {
            if (cur->val < x)
                lt.push(cur->val);
            else
                ge.push(cur->val);

            cur = cur->next;
        }

        if (lt.size() == 0) {
            return head;
        }

        cur = head;

        while (cur) {
            if (!lt.empty()) {
                cur->val = lt.front();
                lt.pop();
            } else if (!ge.empty()) {
                cur->val = ge.front();
                ge.pop();
            }
            cur = cur->next;
        }

        return head;
    }
};

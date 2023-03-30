class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vals({0});
        ListNode* cur = head;
        while (cur) {
            vals.push_back(cur->val);
            cur = cur->next; 
        }

        cur = head;
        int pos = 0;
        int v = left + right;

        while (cur && pos < right) {
            ++pos;

            if (left <= pos)
                cur->val = vals[left + right - pos];

            cur = cur->next;
        }

        return head;
    }
};

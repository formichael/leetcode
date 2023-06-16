class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        ListNode *cur = head;
        while (cur) {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        sort(vals.begin(), vals.end());

        int idx = 0;
        cur = head;
        
        while (cur) {
            cur->val = vals[idx++];
            cur = cur->next;
        }

        return head;
    }
};

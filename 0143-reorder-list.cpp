class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        vector<ListNode*> v;
        ListNode* tmp = head;
        while (tmp) {
            v.push_back(tmp);
            tmp = tmp->next;
        }

        int n = v.size();
        ListNode* cur = head;
        for (int i = 0; i < n / 2; i++) {
            if (cur)
                cur->next = v[i];
            
            v[i]->next = v[n - 1 - i];
            cur = v[n - 1 - i];
            cur->next = nullptr;
        }

        if (n % 2 && cur) {
            cur->next = v[n / 2];
            v[n / 2]->next = nullptr;
        }
    }
};

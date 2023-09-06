class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int listLen = 0;
        ListNode* cur = head;
        while (cur) {
            ++listLen;
            cur = cur->next;
        }

        int div = listLen / k;
        int remain = listLen % k;
        vector lens(k, 0);

        for (int i = 0; i < k; i++) {
            lens[i] = div;
            if (i < remain) {
                lens[i]++;
            }
        }

        cur = head;
        vector<ListNode*> ans(k, nullptr);

        for (int i = 0; i < k; i++) {
            ListNode* last = nullptr;
            for (int j = 0; j < lens[i] && cur != nullptr; j++) {
                if (j == 0) {
                    ans[i] = new ListNode(cur->val);
                    last = ans[i];
                } else {
                    last->next = new ListNode(cur->val);
                    last = last->next;
                }
                cur = cur->next;
            }
        }

        return ans;
    }
};


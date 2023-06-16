class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;
        ListNode* cur = head;

        while (cur) {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        int ans = 0, N = vals.size();
        
        for (int i = 0; i < N / 2; i++) {
            ans = max(vals[i] + vals[N - 1 - i], ans);
        }

        return ans;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *pre = nullptr, *cur = slow, *tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        cur = head;
        int ans = 0;

        while (pre && cur) {
            ans = max(ans, pre->val + cur->val);
            cur = cur->next;
            pre = pre->next;
        }

        return ans;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *, bool> m;
        ListNode *cur = head;

        while (cur) {
            if (auto itr = m.find(cur); itr != m.end()) {
                return true;
            }

            m[cur] = true;
            cur = cur->next;
        }

        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head ? head->next : nullptr;

        while (slow && fast) {
            if (slow == fast) {
                return true;
            }
            
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
        }

        return false;
    }
};

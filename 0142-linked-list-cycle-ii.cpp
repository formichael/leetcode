class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        map<ListNode *, bool> seen;
        ListNode *cur = head;
        
        while (cur) {
            if (auto itr = seen.find(cur); itr != seen.end()) {
                return cur;
            }
            seen[cur] = true;
            cur = cur->next;
        }

        return nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // no cycle
        if (!(fast && fast->next))
            return nullptr;

        ListNode *cur = head;
        while (cur != slow) {
            cur = cur->next;
            slow = slow->next;
        }

        return cur;
    }
};

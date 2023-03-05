class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *slow = head, *fast = head;
        while (fast) {
            if (!fast->next) break; // arrived at the end of the list
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        vector<ListNode*> v;
        ListNode *cur = head;
        while (cur) {
            v.push_back(cur);
            cur = cur->next;
        }

        return v[v.size() / 2];
    }
};

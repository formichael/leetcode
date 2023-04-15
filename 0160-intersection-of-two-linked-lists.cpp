class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> setA;

        ListNode *cur = headA;
        while (cur) {
            setA[cur] = true;
            cur = cur->next;
        }

        cur = headB;
        while (cur) {
            if (auto itr = setA.find(cur); itr != setA.end()) {
                return itr->first;
            }
            cur = cur->next;
        }

        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

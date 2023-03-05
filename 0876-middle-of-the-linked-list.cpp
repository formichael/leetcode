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

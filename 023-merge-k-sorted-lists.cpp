// solution 1: merge sort
class Solution {
public:
    ListNode* merge(ListNode *left, ListNode *right){
        ListNode *head = nullptr, *cur = nullptr;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                if (cur != nullptr) {
                    cur->next = left;
                }
                cur = left;
                left = left->next;
            } else {
                if (cur != nullptr) {
                    cur->next = right;
                }
                cur = right;
                right = right->next;
            }

            if (head == nullptr) {
                head = cur;
            }
        }

        if (left != nullptr) {
            if (cur) {
                cur->next = left;
            } else {
                head = left;
            }
        }
        
        if (right != nullptr) {
            if (cur) {
                cur->next = right;
            } else {
                head = right;
            }
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end)
    {
        if (start >= end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = mergeKLists(lists, start, mid);
        ListNode* right = mergeKLists(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};

// solution 2: simply take all elements together and sort
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        ListNode *n = nullptr;
        for (const auto &list : lists) {
            n = list;
            while (n) {
                vals.push_back(n->val);
                n = n->next;
            }
        }
        sort(vals.begin(), vals.end());

        ListNode *all = nullptr;
        if (vals.empty()) {
            return all;
        }

        ListNode *cur = nullptr;
        for (auto val : vals) {
            ListNode *node = new(ListNode);
            node->val = val;
            node->next = nullptr;

            if (cur == nullptr) {
                cur = node;
                all = cur;
            } else {
                cur->next = node;
                cur = node;
            }
        }

        return all;
    }
};

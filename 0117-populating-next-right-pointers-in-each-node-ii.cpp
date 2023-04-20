class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        queue<Node*> q({root});
        Node* pre = nullptr;

        while(!q.empty()) {
            int qsize = q.size();
            for (int i = qsize; i > 0; i--) {
                Node* node = q.front();
                q.pop();

                if (pre && i != qsize)
                    pre->next = node;

                pre = node;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* node = root;

        while(node) {
            Node dummy(0);
            
            for (Node* needle = &dummy; node; node = node->next) {
                if (node->left) {
                    needle->next = node->left;
                    needle = needle->next;
                }
                if (node->right) {
                    needle->next = node->right;
                    needle = needle->next;
                }
            }

            node = dummy.next; // move to next level
        }

        return root;
    }
};

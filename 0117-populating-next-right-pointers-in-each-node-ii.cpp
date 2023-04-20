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

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v, Node* l, Node* r): value(v), left(l), right(r) {};
};

class BST {
    private:
        Node* root;
        int size;

        void removeNode(Node* target, Node* parent) {
            // 当target左子节点存在时可以不用删除节点，即不用更新parent的子节点连接
            if (target->left != nullptr) { // 第一种情况，target左子节点存在，将左边的最右节点值换上来，再递归remove左边的最右节点
                Node* cur = target->left;
                parent = target;
                while (cur->right != nullptr) {
                    parent = cur;
                    cur = cur->right;
                }
                target->value = cur->value;
                if (parent->left == cur) {
                    parent->left = cur->left;
                } else {
                    parent->right = cur->left;
                }
                delete cur;
                return; 
            }

            if (parent != nullptr) { 
                if (parent->left == target) {
                    parent->left = target->right;
                } else {
                    parent->right = target->right;
                }
            }

            if (target == root) {
                root = target->right;
            }
            delete target;
        }

    public:
        BST() {
            root = nullptr;
            size = 0;
        }

        int treeSize() {
            return size;
        }

        bool contains(int value) {
            Node* cur = root;
            while (cur != nullptr) {
                if (value > cur->value) {
                    cur = cur->right;
                } else if (value < cur->value) {
                    cur = cur->left;
                } else {
                    return true;
                }
            }
            return false;
        }

        void add(int value) {
            if (size == 0) {
                root = new Node(value, nullptr, nullptr);
                size += 1;
                return;
            }

            Node *cur = root, *prev = nullptr;
            while (cur != nullptr) {
                if (value > cur->value) {
                    prev = cur;
                    cur = cur->right;
                } else if (value < cur->value) {
                    prev = cur;
                    cur = cur->left;
                } else {
                    return;
                }
            }

            if (value > prev->value) {
                cur = new Node(value, nullptr, nullptr);
                prev->right = cur;
            } else {
                cur = new Node(value, nullptr, nullptr);
                prev->left = cur;
            }
        }

        void remove(int value) {
            Node *parent = nullptr, *cur = root;
            while (cur != nullptr) {
                if (value > cur->value) {
                    parent = cur;
                    cur = cur->right;
                } else if (value < cur->value) {
                    parent = cur;
                    cur = cur->left;
                } else {
                    removeNode(cur, parent);
                    size -= 1;
                    return;
                }
            }
        }
};
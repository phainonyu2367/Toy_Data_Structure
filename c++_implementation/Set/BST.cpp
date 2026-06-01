class BST {
    private:
        struct Node {
            int value;
            Node* left;
            Node* right;
            Node(int val, Node* l=nullptr, Node* r=nullptr): value(val), left(l), right(l) {};
        };
        Node* root;

        void removeNode(Node* root, Node* prev, bool leftChild) {
            bool tmpPrev = false;
            Node* cur = root;
            if (prev == nullptr) {
                prev = new Node(-1);
                tmpPrev = true;
            }

            if (cur->left == nullptr && cur->right == nullptr) {
                if (leftChild) {
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
                delete cur;
            } else if (cur->left == nullptr && cur->right != nullptr) {
                if (leftChild) {
                    prev->left = cur->right;
                } else {
                    prev->right = cur->right;
                }
                delete cur;
            } else if (cur->left != nullptr && cur->right == nullptr) {
                if (leftChild) {
                    prev->left = cur->left;
                } else {
                    prev->right = cur->left;
                }
                delete cur;
            } else {
                if (tmpPrev) {
                    delete prev;
                }
                prev = cur;
                cur = cur->left;
                while (cur->right != nullptr) {
                    prev = cur;
                    cur = cur->right;
                }
                root->value = cur->value;
                removeNode(cur, prev, leftChild);
            }
        }

    public:
        bool contains(int value) {
            Node* cur = root;
            while (cur != nullptr) {
                if (value > cur->value) {
                    cur = cur->right;
                }

                if (value < cur->value) {
                    cur = cur->left;
                }

                if (value == cur->value) {
                    return true;
                }
            }  
            return false;
        }

        void add(int value) {
            Node* cur = root;
            if (root == nullptr) {
                root = new Node(value);
                return;
            }

            while (true) {
                if (value > cur->value) {
                    if (cur->right == nullptr) {
                        cur->right = new Node(value);
                        return;
                    }
                    cur = cur->right;
                }

                if (value < cur->value) {
                    if (cur->left == nullptr) {
                        cur->left = new Node(value);
                        return;
                    }
                    cur = cur->left;
                }

                if (value == cur->value) {
                    return;
                }
            }
        }

        void remove(int value, Node* cur=nullptr, Node* prev=nullptr) {
            if (cur == nullptr) {
                cur = root;
            }
            bool leftChild = false;
            while (cur != nullptr) {
                if (cur->value == value) {
                    break;
                }

                if (cur->value > value) {
                    prev = cur;
                    cur = cur->right;
                    leftChild = false;
                }

                if (cur->value < value) {
                    prev = cur;
                    cur = cur->left;
                    leftChild = true;
                }
            }
            removeNode(cur, prev, leftChild);
        }
};

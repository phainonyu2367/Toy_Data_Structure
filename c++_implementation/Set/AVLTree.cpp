#include <algorithm>

struct Node {
    int value;
    int height;
    Node* left;
    Node* right;
    Node(int v, Node* l=nullptr, Node* r=nullptr, int h=0): value(v), left(l), right(r), height(h) {};
};

class AVLTree {
    private:
        Node* root;

        int height(Node*& node) {
            if (node == nullptr) {
                return -1;
            } else {
                return node->height;
            }
        }

        void LL(Node*& target) { // 左偏情况
            Node* tl = target->left;
            target->left = tl->right; // 更新target左子节点
            tl->right = target; // 更新tl右子节点
            target->height = std::max(height(target->right), height(target->left)) + 1;
            tl->height = std::max(height(tl->left), height(tl->right)) + 1;
            target = tl; // 将原左子节点连接到原父节点的子节点处
        }

        void RR(Node*& target) { // 右偏情况
            Node* tr = target->right;
            target->right = tr->left; // 更新target右子节点
            tr->left = target; // 更新tr左子节点
            target->height = std::max(height(target->right), height(target->left)) + 1;
            tr->height = std::max(height(tr->left), height(tr->right)) + 1;
            target = tr;
        }

        void LR(Node*& target) {
            RR(target->left);
            LL(target);
        }

        void RL(Node*& target) {
            LL(target->right);
            RR(target);
        }

        void insert(const int& value, Node*& cur) {
            if (cur == nullptr) {
                cur = new Node(value, nullptr, nullptr, 0);
                return;
            } else if (cur->value > value) { // 进入左子树
                insert(value, cur->left);
                if (height(cur->left) - height(cur->right) == 2) { // 进入左子树导致Avl树左偏失衡
                    if (value > cur->left->value) { // cur往左走了，同时失衡保证左子节点一定存在
                        LL(cur);
                    } else {
                        LR(cur);
                    }
                }
            } else if (cur->value < value) { // 进入右子树
                insert(value, cur->right);
                if (height(cur->left) - height(cur->right) == 2) {
                    if (value > cur->right->value) {
                        RL(cur);
                    } else {
                        RR(cur);
                    }
                }
            }

            cur->height = std::max(height(cur->left), height(cur->right)) + 1;
        }

        bool adjust(Node*& cur, bool right) {
            // 进入adjust说明子树高度已经变小
            if (right) { // 
                if (height(cur->left) - height(cur->right) == 1) { // max(left, right)不变 
                    return true;
                }
                
                if (height(cur->left) - height(cur->right) == 0) { // max(left, right)改变
                    cur->height -= 1; // cur height减小
                    return false;
                }

                if (height(cur->left) - height(cur->right) == 2) { // 高度改变且失衡
                    // 需要判断是LL失衡还是LR失衡
                    if (height(cur->left->left) > height(cur->left->right)) { // LL失衡
                        LL(cur);
                        return height(cur->right) != height(cur->left);
                    } else {
                        LR(cur);
                        return false;
                    }
                } 

            } else {
                if (height(cur->left) - height(cur->right) == -1) {
                    return true;
                }

                if (height(cur->left) - height(cur->right) == 0) {
                    cur->height -= 1;
                    return false;
                }

                if (height(cur->left) - height(cur->right) == -2) {
                    if (height(cur->right->right) > height(cur->right->left)) {
                        RR(cur);
                        return height(cur->right) != height(cur->left);
                    } else {
                        RL(cur);
                        return false;
                    }
                }
            }
        }

        bool remove(const int& value, Node*& cur) { // 返回信号给上一阶递归函数确定是否是有高度变化
            if (cur == nullptr) {
                return true; // true返回告诉上一阶函数调用没有height变化
            }

            if (cur->value == value) { // 找到了要删除的节点
                if (cur->left == nullptr || cur->left == nullptr) { // 有0或者1个子节点
                    Node* tmp = cur;
                    cur = (cur->left != nullptr) ? cur->left: cur->right;
                    delete tmp;
                    return false; // 删除造成了高度变化
                } else { // 有2个子节点的情况
                    Node* tmp = cur->right;
                    while (tmp->left != nullptr) { // 找到右子树的最左节点
                        tmp = tmp->left;
                    }
                    cur->value = tmp->value;
                    if (remove(tmp->value, cur->right)) { // 在右子树中删除tmp节点
                        // note: 这里必须从右子树节点开始删除，才能保证这中间的avl更新是正确的，不可以只删除tmp(在BST中就可以)。
                        return true;
                    }
                    return adjust(cur, 1); // 修正右子树变化带来的Avl失衡
                }

                if (cur->value > value) { // 往左子树递归删除
                    if (remove(value, cur->left)) {
                        return true;
                    }
                    return adjust(cur, 0);
                } else { // 往右子树递归删除
                    if (remove(value, cur->left)) {
                        return true;
                    }
                    return adjust(cur, 1);
                }
            }
        }

    public:
        AVLTree() {
            root = nullptr;
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

        void insert(const int& value) {
            insert(value, root);
        }

        void remove(const int& value) {
            remove(value, root);
        }
};
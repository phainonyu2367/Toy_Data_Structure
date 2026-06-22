#include <queue>
#include <iostream>

template<class elemType>
class Node {
    friend class binarySearchTree<elemType>;
    private:
        elemType data;
        Node *left, *right;
};

template<class elemType>
class binarySearchTree {
    private:
        Node<elemType> *root;
    public:
        void remove(const elemType &x, Node<elemType> *&t);
        void levelTraverse() const;
};

template<class elemType>
void binarySearchTree<elemType>::remove(const elemType &x, Node<elemType> *&t) {
    if (t == nullptr) { // t是空指针的情况，不做处理
        return;
    }

    if (t->data < x) {
        remove(x, t->right);
        return;
    } else if (t->data > x) {
        remove(x, t->left);
        return;
    }

    if (t->left != nullptr && t->right != nullptr) {
        Node<elemType>* cur = t->right; // 找右子树的最左子节点
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        t->data = cur->data;
        remove(t->data, t->right);
        return;
    }

    Node<elemType> *replacement = (t->left != nullptr) ? t->left : t->right;
    delete t;
    t =  replacement;
    return;
}

template<class elemType>
void binarySearchTree<elemType>::levelTraverse() const {
    if (root == nullptr) {
        return;
    }

    std::queue<Node<elemType>*> levelTraverseQueue;
    levelTraverseQueue.push(root);
    Node<elemType>* curNode;
    while (!levelTraverseQueue.empty()) {
        curNode = levelTraverseQueue.front();
        levelTraverseQueue.pop();
        if (curNode->left != nullptr) {
            levelTraverseQueue.push(curNode->left);
        }
        if (curNode->right != nullptr) {
            levelTraverseQueue.push(curNode->right);
        }
        std::cout << curNode->data << ' ';
    }
}
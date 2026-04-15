#include <iostream>
#include <vector>
#include <queue>

template<typename T, T NULL_VALUE>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(): value(NULL_VALUE), left(nullptr), right(nullptr) {};
    Node(const T& val, Node* l = nullptr, Node* r = nullptr):
        value(val), left(l), right(r) {};
};

template<typename T, T NULL_VALUE>
class BinaryTree {
    private:
        std::stack<Node*> constructStack;
        Node* root;
        int size;
        int height;

    public:
        BinaryTree(std::vector<T> numSerie);
        ~BinaryTree();
        void preOrderTraverse();
        void inOrderTraverse();
        void postOrderTraverse();
        void levelOrderTraverse();
        int size() {
            return size;
        }
        int height() {
            return height;
        }
        bool empty() {
            return root == nullptr;
        }
        bool ifLeaf(Node* node) {
            return node->left == nullptr && node->right == nullptr;
        }
};

template<typename T, T NULL_VALUE>
BinaryTree<T, NULL_VALUE>::BinaryTree(std::vector<T> numSerie) {
    /*
    Construct function of the binary tree
    @param
        - vector<int> numSerie: level-order index series of the tree
    */
    std::queue<Node*> treeQueue = new std::vector<Node*>;
    Node* cur; int count = 1;
    T left, right;

    if (numSerie.empty()) {
        return;
    } else {
        root = new Node(numSerie[0]);
        treeQueue.push(root);
    }

    while (!treeQueue.empty()) {
        cur = treeQueue.pop();
    }
}

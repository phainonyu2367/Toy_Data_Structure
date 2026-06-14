#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v, Node* l=nullptr, Node* r=nullptr): value(v), left(l), right(r) {};
};

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return a->value > b->value;
    }
};

Node* buildHuffmanTree(std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }

    Node *cur, *left, *right;
    while (nodes.size() > 1) {
        left = nodes.top();
        nodes.pop();
        right = nodes.top();
        nodes.pop();
        cur = new Node(left->value + right->value, left, right);
        nodes.push(cur);
    }
    return nodes.top();
}

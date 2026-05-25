#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int v=-1, Node* n=nullptr, Node* p=nullptr): value(v), next(n) {};
};


class LinkedList {
    private:
        Node* head;
        Node* back;
        int size;

    public:
        LinkedList() {
            head = new Node();
            back = head;
            size = 0;
        }

        ~LinkedList() {
            Node* cur = head;
            Node* prev = head;
            while (cur != nullptr) {
                cur = cur->next;
                delete prev;
                prev = cur;
            }
        }

        int size() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void add(int value) {
            back->next = new Node(value);
            back = back->next;
            size += 1;
        }

        void remove(int index) {
            if (index >= size || index < 0) {
                std::cout << "Invalid index.";
                return;
            }
            Node* cur = head;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
            size -= 1;
        }

        int get(int index) {
            if (index >= size || index < 0) {
                std::cout << "Invalid index.";
                return;
            }
            Node* cur = head->next;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            return cur->value;
        }

        int find(int value) {
            Node* cur = head->next;
            int index = 0;
            while (cur != nullptr) {
                if (cur->value == value) {
                    return index;
                }
            }
            return -1;
        }

        void insert(int index, int value) {
            if (index <= 0 || index > size) {
                std::cout << "Invalid index.";
                return;
            }
            Node* cur = head;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            cur->next = new Node(value, cur->next);
            size += 1;
        }
};
#include<iostream>

template<typename T>
class SLList {
    private:
        struct Node {
            T value;
            Node* next;
            Node(T v, Node* n): value(v), next(n) {}
        };

        int size;
        Node* head;
        Node* tail;

    public:
        /*TODO:
            implement the basic method of the data structure
            1. init     ✔️
            2. clear    ✔️
            3. remove   ✔️
            4. insert   ✔️
            5. find     ✔️
            6. set      ✔️
            7. add      ✔️
            8. size     ✔️
            9. get      ✔️
            10. pointer ✔️
        */ 

        class Iterator {
            // Enclosured pointer, save to operate meanwhile saved the flexibility of Linked List.
            private:
                Node* cur;

            public:
                Iterator(Node* n): cur(n) {};

                Iterator& operator++() {
                    if (cur) {
                        cur = cur->next;
                    }
                    return *this;
                }

                bool operator!=(const Iterator& other) const {
                    return cur != other.cur;
                }

                T& operator*() const {
                    return cur->value;
                }
        };

        Iterator begin() {
            return ++Iterator(head);
        }

        Iterator end() {
            return Iterator(tail);
        }

        SLList() {
            // Init function of the list, initializing head and size
            head = new Node(T(), nullptr);
            // Using cache to avoid wasting of time
            size = 0;
            tail = head;
        }

        void addLast(T val) {
            // Add a node to the end of the list
            tail->next = new Node(val, NULL);
            tail = tail->next;
            size++;
        }

        void addFirst(T val) {
            // Add a node to the begining of the list
            Node* cur = head;
            cur->next = new Node(val, cur->next);
            if (cur->next->next == nullptr) tail = cur->next;
            size++;
        }

        ~SLList() {
            // Destruction function of the list
            Node* cur = head;
            while (cur != NULL) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }

        void clear() {
            Node* cur = head->next;
            Node* prev;
            while (cur != NULL) {
                prev = cur;
                cur = cur->next;
                delete prev;
            }
            head->next = NULL;
            tail = head;
            size = 0;
        }

        int getSize() const {
            // return the size of the list
            return size;
        }

        int findPos(T val) const {
            // Return the index of the first node which have the target value in the list
            int idx = 0;
            Node* cur = head->next;
            while (cur != NULL) {
                if (cur->value == val) {
                    return idx;
                }
                idx++;
                cur = cur->next;
            }
            return -1;
        }

        T get(int idx) const {
            // Get the value of ith node.
            if (idx >= size || idx < 0) {             
                throw std::out_of_range("Invalid index."); // because the value type is not sure, so we use the default value in head
            }
            Node* cur = head;
            for (int i = 0; i <= idx; i++) {
                cur = cur->next;
            }
            return cur->value;
        }

        void insert(int idx, T val) {
            // Insert a node at position i.
            if (idx < 0 || idx > size) {
                std::cout << "ValueError(insert): Invalid index.";
                return;
            }
            Node* cur = head;
            for (int i = 0; i < idx; i++) {
                cur = cur->next;
            }
            cur->next = new Node(val, cur->next);
            if (idx == size) tail = cur->next;
            size++;
        }

        void remove(int idx) {
            // Remove a node at position i.
            if (idx < 0 || idx >= size) {
                std::cout << "ValueError(remove): Invalid index.";
                return;
            }
            Node* cur = head;
            for (int i = 0; i < idx; i++) {
                cur = cur->next;
            }
            Node* temp = cur->next;
            cur->next = temp->next;
            if (cur->next == nullptr) tail = cur;
            delete temp;
            size--;
        }

        void set(int idx, T val) {
            if (idx < 0 || idx >= size) {
                std::cout << "ValueError(set): Invalid index.";
                return;
            }
            Node* cur = head;
            for (int i = 0; i <= idx; i++) {
                cur = cur->next;
            }
            cur->value = val;
        }

        // 禁用拷贝
        SLList(const SLList& p) {
            head = new Node(T(), nullptr);
            tail = head;
            Node* cur = p.head->next;
            while (cur != nullptr) {
                this->addLast(cur->value);
                cur = cur->next;
            }
        }

        SLList& operator=(const SLList& p) {
            // 自赋值检查
            if (this == &p) {
                return *this;
            }

            Node* cur = head->next;
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp; // 释放旧节点内存
            }
            // 重置 head 和 tail
            head->next = nullptr; 
            tail = head;
            cur = p.head->next;
            while (cur != nullptr) {
                this->addLast(cur->value);
                cur = cur->next;
            }

            return *this;
        }
};
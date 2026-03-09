#include<iostream>
#include<optional>

template<typename T>
class SLList {
    private:
        struct Node {
            T value;
            Node* next;
            Node(T v, Node* n) {
                value = v;
                next = n;
            }
        }

        Node* head;
        int size;

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
        */ 

        SLList() {
            // Init function of the list, initializing head and size
            head = new Node();
            // Using cache to avoid wasting of time
            size = 0;
        }

        void addLast(T val) {
            // Add a node to the end of the list
            Node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = new Node(val, NULL);
            size++;
        }

        void addFirst(T val) {
            // Add a node to the begining of the list
            cur->next = new Node(val, cur->next);
            size++;
        }

        ~SLList() {
            // Destruction function of the list
            Node* cur = head;
            while (cur != NULL) {
                head = cur;
                cur = cur->next;
                delete head;
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
            size = 0;
        }

        int size() {
            // return the size of the list
            return size;
        }

        int findPos(T val) {
            // Return the index of the first node which have the target value in the list
            int idx = 0;
            Node* cur = head->next;
            while (cur != NULL) {
                if (cur->value == val) {
                    return idx;
                }
                idx++;
            }
            return -1;
        }

        T get(int idx) {
            // Get the value of ith node.
            if (idx >= size || idx < 0) {
                std::cout << "ValueError(get): Invalid index.";
                return head->value; // because the value type is not sure, so we use the default value in head
            }
            Node* cur = head;
            while (idx >= 0) {
                cur = cur->next;
                idx--;
            }
            return cur->value;
        }

        void insert(int idx, T val) {
            // Insert a node at position i.
            if (idx < 0 || idx > size) {
                std::cout << "ValueError(insert): Invalid index."
                return;
            }
            Node* cur = head;
            while (idx > 0) {
                cur = cur->next;
                idx--;
            }
            cur->next = new Node(val, cur->next);
        }

        void remove(int idx) {
            // Remove a node at position i.
            if (idx < 0 || idx >= size) {
                std::cout << "ValueError(remove): Invalid index."
                return;
            }
            Node* cur = head;
            while (idx > 0) {
                cur = cur->next;
                idx--;
            }
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }

        void set(int idx, T val) {
            if (idx < 0 || idx >= size) {
                std::cout << "ValueError(set): Invalid index.";
                return;
            }
            Node* cur = head;
            while (idx >= 0) {
                cur = cur->next;
                idx--;
            }
            cur->value = val;
        }
};
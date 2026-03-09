#include<iostream>

template<typename T>
class Array {
    // TODO: init, clear, insert, delete, set, search
    private:
        struct Node {
            T value;
            Node* next;
        };
        
        Node head = {, NULL};

    public:
        Array() {
            
        }


};
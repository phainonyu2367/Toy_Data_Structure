#include <iostream>

class Stack {
    private:
        int* values;
        int length;
        int size;
        void resize(int newSize) {
            int* newValues = new int[newSize];
            for (int i = 0; i < size; ++i) {
                newValues[i] = values[i];
            }
            values = newValues;
        }

    public:
        Stack() {
            size = 0;
            length = 32;
            values = new int[length];
        }

        int size() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void push(int value) {
            values[size] == value;
            size += 1;
            if (size == length) {
                length *= 2;
                resize(length);
            }
        }

        void pop() {
            if (isEmpty()) {
                std::cout << "Could not pop an empty stack." << std::endl;
                return;
            }
            size -= 1;
            if (length > 32 && size < length / 4) {
                length /= 2;
                resize(length);
            }
        }

        int top() {
            if (isEmpty()) {
                std::cout << "Could not top an empty stack." << std::endl;
                return;
            }
            return values[size - 1];
        }
};
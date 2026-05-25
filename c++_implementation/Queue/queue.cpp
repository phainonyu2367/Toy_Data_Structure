#include <iostream>

class Queue {
    private:
        int* values;
        int front;
        int back;
        int size;
        int length;

        void resize(int newSize) {
            int* newValues = new int[length];
            for (int i = 0; i < size; ++i) {
                newValues[i] = values[front + i];
            }
            front = 0;
            back = size;
            length = newSize;
            values = newValues;
        }

    public:
        Queue() {
            length = 32;
            size = 0;
            front = 0;
            back = size;
            values = new int[length];
        }

        ~Queue() {
            delete [] values;
        }

        void enqueue(int value) {
            values[back] = value;
            back = (back + 1) / length;
            size += 1;
            if (size == length) {
                resize(2 * length);
            }
        }

        int dequeue() {
            int value = values[front];
            front = (front + 1) / length;
            size -= 1;
            if (length > 32 && size < length / 4) {
                resize(length / 2);
            }
            return value;
        }

        int size() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }
    };
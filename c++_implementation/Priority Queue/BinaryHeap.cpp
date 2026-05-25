#include <iostream>

class PriorityQueue {
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
            length = newSize;
        }

        void swap(int a, int b) {
            values[a] = values[a] + values[b];
            values[b] = values[a] - values[b];
            values[a] = values[a] - values[b];
        }

        void heapifyUp(int index) {
            if (index == 0 || values[index] >= values[(index - 1) / 2]) {
                return;
            }
            swap(index, (index - 1) / 2);
            heapifyUp((index - 1) / 2);
        }

        void heapifyDown(int index) {
            if (index >= size || values[index] <= values[2*index + 1] || values[index] <= values[2*index + 2]) {
                return;
            }
            if (values[index] > values[2*index + 1]) {
                swap(index, 2*index + 1);
                heapifyDown(2*index + 1);
                return;
            } else if (values[index] > values[2*index + 2]) {
                swap(index, 2*index + 2);
                heapifyDown(2*index + 2);
            }
        }

    public:
        PriorityQueue() {
            length = 32;
            size = 0;
            values = new int[length];
        }

        ~PriorityQueue() {
            delete [] values;
        }
        
        void push(int value) {
            values[size] = value;
            size += 1;
            heapifyUp(size);
            if (size == length) {
                resize(2 * length);
            }
        }

        int pop() {
            int value = values[0];
            values[0] = values[size - 1];
            size -= 1;
            heapifyDown(0);
            if (length > 32 && size < length / 4) {
                resize(length / 2);
            }
            return value;
        }
};
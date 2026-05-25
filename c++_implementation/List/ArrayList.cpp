#include <iostream>

class ArrayList {
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
        ArrayList() {
            size = 0;
            length = 32;
            values = new int[length];
        }

        ~ArrayList() {
            delete [] values;
        }

        bool isEmpty() {
            return size == 0;
        }

        int size() {
            return size;
        }

        int get(int index) {
            return values[index];
        }

        void add(int value) {
            values[size] = value;
            if (size == length) {
                length *= 2;
                resize(length);
            }
        }

        void remove(int index) {
            if (index < 0 || index >= size) {
                std::cout << "Invalid index.";
                return;
            }
            for (int i = index; i < size; ++i) {
                values[i] = values[i + 1];
            }
            size -= 1;
            if (length > 32 && size < length / 4) {
                length /= 2;
                resize(length);
            }
        }

        void insert(int index, int value) {
            if (index < 0 || index >= size) {
                std::cout << "Invalid index.";
                return;
            }
            for (int i = size; i > index; --i) {
                values[i] = values[i - 1];
            }
            values[index] = value;
            size += 1;
            if (size == length) {
                length *= 2;
                resize(length);
            }
        }

        int find(int value) {
            for (int i = 0; i < size; ++i) {
                if (values[i] == value) {
                    return i;
                }
            }
            return -1;
        }
};

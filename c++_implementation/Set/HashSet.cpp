#include <list>
class HashSet {
    private:
        std::list<int>* values;
        int size;
        int length;
        double R;
        int hash(int value) {
            return value % length;
        }

        void resize(int newSize) {
            int prevLength = length;
            length = newSize;
            std::list<int>* newValues = new std::list<int>[length];
            for (int i = 0; i < prevLength; ++i) {
                for (int val: values[i]) {
                    newValues[hash(val)].push_back(val);
                }
            }    
            delete [] values;
            values = newValues;
        }

    public:
        HashSet() {
            R = 1.5;
            length = 32;
            size = 0;
            values = new std::list<int>[length];
        }

        ~HashSet() {
            delete[] values;
        }

        bool contains(int value) {
            int key = hash(value);
            for (int i: values[key]) {
                if (i == value) {
                    return true;
                }
            }
            return false;
        }

        void add(int value) {
            int key = hash(value);
            for (int i: values[key]) {
                if (i == value) {
                    return;
                }
            }
            values[key].push_back(value);
            size += 1;
            if ((double) size / length >= R) {
                resize(2 * length);
            }
        }

        void remove(int value) {
            if (contains(value)) {
                int key = hash(value);
                size -= 1;
                values[key].remove(value);
            }
            if (length > 32 && (double) size / length < 0.75) {
                resize(length / 2);
            }
        }
};

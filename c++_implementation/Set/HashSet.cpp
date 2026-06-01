#include <list>
class HashSet {
    private:
        std::list<int>* values;
        int size;
        int length;
        double R;
        int hash(int value) {
            return value % 31;
        }

        void resize(int newSize) {
            std::list<int>* newValues = new std::list<int>[newSize];
            for (int i = 0; i < length; ++i) {
                for (int val: values[i]) {
                    newValues[hash(val)].push_back(val);
                }
            }    
            length = newSize;
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
            if (size / length >= R) {
                resize(2 * length);
            }
        }

        void remove(int value) {
            int key = hash(value);
            values[key].remove(value);
            size -= 1;
            if (length > 32 && size / length < 0.75) {
                resize(2 * length);
            }
        }
};

#include<iostream>

template<typename T>
class Array {
    /* TODO:
            1. init    ✔️ 
            2. clear   ✔️
            3. remove  ✔️
            4. insert  ✔️
            5. find    ✔️
            6. set     ✔️ 
            7. add     ✔️
            8. size    ✔️ 
            9. get     ✔️
            10. double ✔️
    */
    private:  
        int MAXSIZE = 100; //Fixed maxsize of array
        T* data;
        int size;

        void copy(T* t1, T* t2, int size) {
            /*  Deep copy helper method, copy the content from t1 to t2.
                Asserted that the size of two arrays are valid.
            */
            for (int i = 0; i < size; i++) {
                t2[i] = t1[i];
            }
        }

    public:
        Array(const T* t, int n) {
            // Init method when passing data in.
            data = new T[MAXSIZE];
            size = 0;
            for (int i = 0; i < MAXSIZE && i < n; i++) {
                data[i] = t[i];
                size++;
            }
        }

        Array() {
            // Init method when there is no data.
            data = new T[MAXSIZE];
            size = 0;
        }

        ~Array() {
            // Clear method for array.
            delete [] data;
        }

        int find(T val) {
            // Return the first item equal to val.
            for (int idx = 0; idx < size; idx++) {
                if (val == data[idx]) {
                    return idx;
                }
            }
            return -1;
        }

        int getSize() {
            // Return the size of the array.
            return size;
        }

        T get(int idx) {
            if (idx < 0 || idx >= size) {
                throw "Invalid index(get).";
            }
            return data[idx];
        }

        void doubleMaxSize() {
            // Double the size of the array.
            MAXSIZE *= 2;
            T* temp = new T[MAXSIZE];
            copy(data, temp, size);
            delete [] data;
            data = temp;
        }

        void add(T val) {
            // Add an item at the end of the array.
            if (size >= MAXSIZE) {
                doubleMaxSize();
            }
            data[size] = val;
            size++;
        }

        void set(int idx, T val) {
            // Update the ith item of the array.
            if (idx < 0 || idx >= size) {
                throw "Invalid index(set).";
            }
            data[idx] = val;
        }

        void remove(int idx) {
            // Remove the ith item of the array.
            if (idx < 0 || idx >= size) {
                throw "Invalid index(remove).";
            }
            for (int i = idx; i < size - 1; i++) { // We must use size instead of MAXSIZE
                // Use size to avoid junk data disturbance.
                data[i] = data[i+1];
            }
            size--;
        }

        void insert(int idx, T val) {
            if (idx < 0 || idx > size) {
                throw "Invalid index(insert)";
            }
            if (size == MAXSIZE) {
                doubleMaxSize();
            }
            for (int i = size; i > idx; i--) {
                data[i] = data[i - 1];
            }
            data[idx] = val;
            size++;
        }
};
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
            delete [] values;
            values = newValues;
            length = newSize;
        }

        void swap(int a, int b) {
            int tmp = values[a];
            values[a] = values[b];
            values[b] = tmp;
        }

        void heapifyUp(int index) {
            if (index == 0 || values[index] >= values[(index - 1) / 2]) {
                return;
            }
            swap(index, (index - 1) / 2);
            heapifyUp((index - 1) / 2);
        }

        void heapifyDown(int index) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && values[left] < values[smallest]) {
                smallest = left;
            }
            if (right < size && values[right] < values[smallest]) {
                smallest = right;
            }
            if (smallest != index) {
                swap(smallest, index);
                heapifyDown(smallest);
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
            heapifyUp(size);
            size += 1;
            if (size == length) {
                resize(2 * length);
            }
        }

        int pop() {
            if (size == 0) {
                return -1;
            }
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

void heapSort(int* values, int size) {
    PriorityQueue heap;
    for (int i = 0; i < size; ++i) {
        heap.push(values[i]);
    }

    for (int i = 0; i < size; ++i) {
        values[i] = heap.pop();
    }
}

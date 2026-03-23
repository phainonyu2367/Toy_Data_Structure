#ifndef seqQueue_h
#define seqQueue_h

#include<iostream>

template<class T>
class seqQueue {
    // directed queue implementation based on array

    private:
        T* data;
        int maxSize;
        int head; // head idx, always points at the empty box
        int tail; // tail idx, always points at the last box
        void reSize(int size);
    public:
        seqQueue();
        ~seqQueue();
        void printQueue() const;
        void enQueue(const T& val);
        T deQueue();
        T getHead() const; 
        bool isempty() const;
};

template<class T>
seqQueue<T>::seqQueue() {
    maxSize = 10;
    data = new T[maxSize];
    head = 0; tail = 0;
}

template<class T>
bool seqQueue<T>::isempty() const {
    return head % maxSize == tail % maxSize;
}

template<class T>
void seqQueue<T>::enQueue(const T& val) {
    if ((tail + 1) % maxSize == head % maxSize) reSize(2 * maxSize);
    data[(++tail) % maxSize] = val;
}

template<class T>
T seqQueue<T>::deQueue() {
    if (seqQueue::isempty()) {
        throw "Error, empty queue, cannot deQueue";
    }
    if (maxSize > 10 && tail - head < maxSize / 4) reSize(maxSize / 2);
    return data[(++head) % maxSize];
}

template<class T>
seqQueue<T>::~seqQueue() {
    delete [] data;
}

template<class T>
void seqQueue<T>::reSize(int size) {
    T* tmp = new T[size];
    int len = tail - head;
    for (int i = 1; i <= len; i++) {
        tmp[i] = data[(head + i) % maxSize];
    }
    maxSize = size;
    head = 0; tail = len;
    delete [] data;
    data = tmp;
}

template<class T>
T seqQueue<T>::getHead() const {
    if (seqQueue::isempty()) {
        throw "Error, empty queue, cannot getHead";
    }
    return data[(head + 1) % maxSize];
}

template<class T>
void seqQueue<T>::printQueue() const {
    for (int i = 1; i <= tail - head; i++) {
        std::cout << data[(head + i) % maxSize];
    }
    std::cout << std::endl;
}

#endif
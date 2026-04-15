# ifndef stack_h
# define stack_h
# include <string>

template<typename T>
class Stack {
    // 基于数组的栈声明
    private:
        int maxsize;
        int idx;
        T* data;
        void doubleSize();
    public:
        Stack();
        ~Stack() {
            delete [] data;
        }
        void push(const T& val);
        T pop();
        T top() const;
        bool isempty() const;
};

template<typename T>
Stack<T>::Stack() {
    maxsize=20;
    idx = -1;
    data = new T[maxsize];
}

template<typename T>
void Stack<T>::doubleSize() {
    // 默认调用doublesize的时候是栈满的时候
    T* temp = new T[maxsize * 2];
    for (int i = 0; i < maxsize; i++) {
        temp[i] = data[i];
    }
    maxsize *= 2;
    delete [] data;
    data = temp;
}

template<typename T>
void Stack<T>::push(const T& val) {
    if (idx == maxsize - 1) doubleSize();
    idx++; data[idx] = val;
}

template<typename T>
T Stack<T>::pop() {
    if (idx == -1) {
        std::cerr << "Error, the stack is empty, cannot pop.";
    }
    return data[idx--];
}

template<typename T>
bool Stack<T>::isempty() const {
    return idx == -1;
}

template<typename T>
T Stack<T>::top() const {
    if (isempty()) {
        std::cerr << "Error, the stack is empty, cannot get top.";
    }
    return data[idx];
}
# endif
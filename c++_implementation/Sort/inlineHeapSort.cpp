#include <vector>

void inlineBuildHeap(std::vector<int>& values) {
    for (int i = 1; i < values.size(); ++i) {
        int idx = i, parent = (idx - 1) / 2, temp;
        while (idx != 0 && values[idx] > values[parent]) {
            temp = values[parent];
            values[parent] = values[idx];
            values[idx] = temp;
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}

void pop(std::vector<int>& values, int size) {
    int top = values[0];
    values[0] = values[size];
    int curPos = 0, temp, left, right, biggest;
    while (curPos < size) {
        temp = values[curPos];
        biggest = curPos;
        right = 2 * curPos + 2;
        left = 2 * curPos + 1;
        if (left < size && values[left] > values[biggest]) {
            biggest = left;
        }
        if (right < size && values[right] > values[biggest]) {
            biggest = right;
        }
        if (biggest != curPos) {
            values[curPos] = values[biggest];
            curPos = biggest;
            values[curPos] = temp;
        } else {
            break;
        }
    }

    values[size] = top;
}

void inlineHeapSort(std::vector<int>& values) {
    inlineBuildHeap(values);
    for (int i = values.size() - 1; i >= 0; --i) {
        pop(values, i);
    }
}

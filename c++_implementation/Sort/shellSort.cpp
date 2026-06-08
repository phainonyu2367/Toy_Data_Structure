#include <vector>

std::vector<int> getGap(int size) {
    std::vector<int> gaps;
    int curGap = 1;
    while (curGap < size / 3) {
        gaps.push_back(curGap);
        curGap = 3 * curGap + 1;
    }
    return gaps;
}

void insertionSort(std::vector<int>& values, int size, int head, int gap) {
    int value, j;
    for (int i = 1; i < size; ++i) {
        value = values[head + i * gap];
        j = i - 1;
        while (j >= 0 && values[head + j * gap] > value) {
            values[gap * (j + 1) + head] = values[gap * j + head];
            j -= 1;
        }
        values[gap * (j + 1) + head] = value;
    }
}

void shellSort(std::vector<int>& values) {
    std::vector<int> gaps = getGap(values.size());
    int curGap, size, curVal;
    for (int i = gaps.size() - 1; i >= 0; --i) {
        curGap = gaps[i];
        for (int j = 0; j < curGap; ++j) {
            size = (values.size() - j) / curGap;
            insertionSort(values, size, j, curGap);
        }
    }
}

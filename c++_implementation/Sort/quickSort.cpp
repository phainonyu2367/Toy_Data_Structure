#include <vector>

void partition(std::vector<int>& values, int low, int high) {
    int left, right, hole;
    while (low < high) {
        left = low;
        right = high;
        hole = values[left];
        while (left < right) {
            while (values[right] > hole) {
                right -= 1;
            }
            values[left] = values[right];
            while (values[left] <= hole && left < right) {
                left += 1;
            }
            values[right] = values[left];
            partition(values, low, left - 1);
        }
        values[left] = hole;
        low += 1;
    }
}

void quickSort(std::vector<int>& values) {
    partition(values, 0, values.size() - 1);
}   

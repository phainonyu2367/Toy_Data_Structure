void swap(int* values, int aIndex, int bIndex) {
    values[aIndex] = values[aIndex] + values[bIndex];
    values[bIndex] = values[aIndex] - values[bIndex];
    values[aIndex] = values[aIndex] - values[bIndex];
}

void bubbleSort(int* values, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (values[j] > values[j + 1]) {
                swap(values, j, j+1);
            }
        }
    }   
}

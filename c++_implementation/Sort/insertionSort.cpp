void insertionSort(int* values, int size) {
    int value, j;
    for (int i = 1; i < size; ++i) {
        value = values[i];
        j = i - 1;
        while (j >= 0 && values[j] > value) {
            values[j + 1] = values[j];
            --j;
        }
        values[j + 1] = value;
    }
}

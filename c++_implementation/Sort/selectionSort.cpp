void swap(int* values, int aIndex, int bIndex) {
    values[aIndex] = values[aIndex] + values[bIndex];
    values[bIndex] = values[aIndex] - values[bIndex];
    values[aIndex] = values[aIndex] - values[bIndex];
}

void selectionSort(int* values, int size) {
    int minNum, minIndex;
    for (int i = 0; i < size; ++i) {
        minIndex = i;
        minNum = values[i];
        for (int j = i + 1; j < size; ++j) {
            if (values[j] < minNum) {
                minNum = values[j];
                swap(values, j, minIndex);
                minIndex = j;
            }
        }
    }
}
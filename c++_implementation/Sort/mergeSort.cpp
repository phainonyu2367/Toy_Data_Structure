void mergeSort(int* values, int low, int high) {
    int mid = (low + high) / 2;
    if (mid == low) {
        return;
    }
    mergeSort(values, low, mid);
    mergeSort(values, mid, high);

    int* tmpValue = new int[high - low];
    int i = low, j = mid, k = 0;
    while (i < mid && j < high) {
        if (values[i] <= values[j]) {
            tmpValue[k] = values[i];
            i += 1;
            k += 1; 
        } else {
            tmpValue[k] = values[j];
            j += 1;
            k += 1;
        }
    }

    while (i < mid) {
        tmpValue[k] = values[i];
        i += 1;
        k += 1;
    }

    while (j < high) {
        tmpValue[k] = values[j];
        j += 1;
        k += 1;
    }

    k = 0;
    for (int idx = low; idx < high; ++idx) {
        values[idx] = tmpValue[k];
        k += 1;
    }
    delete [] tmpValue;
}
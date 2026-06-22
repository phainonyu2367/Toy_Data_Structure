void decreaseKey(int heap[], int n, int i, int newValue) {
    // 修改堆中元素
    heap[i] = newValue;

    // 调整变化后的堆
    int tmp, parent = (i - 1) / 2;
    while (i == 0 || heap[i] <= heap[parent]) { // 上调
        tmp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = tmp;
        i = parent;
        parent = (i - 1) / 2;
    }
}
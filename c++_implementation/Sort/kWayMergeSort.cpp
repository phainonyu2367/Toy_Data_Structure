#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

void kWayMerge(int* values, int low, int high, std::vector<int>& beg, std::vector<int>& end) {
    int length = high - low + 1;
    std::vector<int> newValues(length);

    struct mergeNode {
        int value;
        int chunkIndex;
        int pos;
    };

    struct mergeComparator {
        bool operator()(const mergeNode& a, const mergeNode& b) const {
            return a.value > b.value;
        }
    };

    std::priority_queue<mergeNode, std::vector<mergeNode>, mergeComparator> pq;
    for (int i = 0; i < beg.size(); ++i) {
        if (beg[i] <= end[i]) { // 初始化最小堆
            pq.push({values[beg[i]], i, beg[i]});
        }
    }

    int newValuesIndex = 0;
    while (!pq.empty()) {
        mergeNode curNode = pq.top();
        pq.pop();

        newValues[newValuesIndex++] = curNode.value;

        int nextPos = curNode.pos + 1;
        if (nextPos <= end[curNode.chunkIndex]) {
            pq.push({values[nextPos], curNode.chunkIndex, nextPos});
        }
    }

    for (int i = 0; i < length; ++i) {
        values[low + i] = newValues[i];
    }
}

void kWayMergeSort(int* values, int low, int high, int k) {
    int length = high - low + 1;
    if (length <= 1) { // 如果划分已经足够小就返回
        return;
    }

    int chunkNum = std::min(length, k); // 分块数量，如果分块数大于vec长度就只能取length个（chunk最长为1）
    int chunkSize = length / chunkNum; // 分块大小
    int remainder = length % chunkNum; // 按照k均分长度的分块余量，在一会决定分块起始的时候会用到

    std::vector<int> beg(chunkNum);
    std::vector<int> end(chunkNum);

    // 初始化起点和终点数值
    int curLow = low;
    for (int i = 0; i < chunkNum; ++i) {
        beg[i] = curLow;
        curLow += chunkSize + (i < remainder ? 1 : 0);
        end[i] = curLow - 1;
    }

    for (int i = 0; i < chunkNum; ++i) {
        kWayMergeSort(values, beg[i], end[i], chunkNum); // 对每一个分块内部递归归并排序
    }

    kWayMerge(values, low, high, beg, end);
}

void kWayMergeSort(int* values, int length, int k) {
    if (k <= 1) {
        std::cout << "Invalid value k.";
        return;
    }
    kWayMergeSort(values, 0, length - 1, k);
}

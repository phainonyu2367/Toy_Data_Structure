// use adjacency list to represent graphs
#include <vector>
#include <queue>
#include <iostream>

std::vector<int> topologicalSort(std::vector<std::vector<int>> const& graph) {
    // 入度初始化
    int size = graph.size();
    int* inDegree = new int[size]{0};
    std::vector<int> topoSeq;
    topoSeq.resize(size, 0);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            inDegree[graph[i][j]] += 1;
        }
    }

    // 寻找拓扑排序初始0入度点
    std::queue<int> entryQueue;
    for (int i = 0; i < size; ++i) {
        if (inDegree[i] == 0) {
            entryQueue.push(i);
        }
    }

    // 开始拓扑排序
    int popOutVertex, tmpVertex;
    while (!entryQueue.empty()) {
        popOutVertex = entryQueue.front();
        entryQueue.pop();
        for (int i = 0; i < graph[popOutVertex].size(); ++i) {
            tmpVertex = graph[popOutVertex][i];
            inDegree[tmpVertex] -= 1;
            if (inDegree[tmpVertex] == 0) {
                entryQueue.push(tmpVertex);
            }
        }
        topoSeq.push_back(popOutVertex);
    }

    delete[] inDegree;
    return topoSeq;
}

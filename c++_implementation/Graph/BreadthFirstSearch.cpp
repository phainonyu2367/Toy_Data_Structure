#include <iostream>
#include <vector>
#include <queue>
// assume the graph information is stored in the adjacency list
void BFS(std::vector<std::vector<int>> graph, int size) {
    std::queue<int> bfsQueue;
    std::vector<bool> visited;
    visited.resize(size, false);
    int cur;
    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            bfsQueue.push(i);
            visited[cur] = true;
            while (!bfsQueue.empty()) {
                cur = bfsQueue.front();
                bfsQueue.pop();
                std::cout << cur;
                for (int j = 0; j < graph[cur].size(); ++j) {
                    if (!visited[graph[cur][j]]) {
                        bfsQueue.push(graph[cur][j]);
                        visited[graph[cur][j]] = true;
                    }
                }            
            }
        }
    }
}

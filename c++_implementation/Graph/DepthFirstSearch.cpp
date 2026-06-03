#include <iostream>
#include <vector>
#include <stack>
// assume the graph information stores in a adjacency list
void BFS(std::vector<std::vector<int>> graph, int size) {
    std::vector<bool> visited;
    visited.resize(size, false);
    std::stack<int> DFSstack;
    int cur;
    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            DFSstack.push(i);
            visited[i] = true;
            while (!DFSstack.empty()) {
                cur = DFSstack.top();    
                DFSstack.pop();
                std::cout << cur;
                for (int j = 0; j < graph[cur].size(); ++j) {
                    if (!visited[graph[cur][j]]) {
                        DFSstack.push(graph[cur][j]);
                        visited[graph[cur][j]] = true;
                    }
                }
            }
        }
    }
}
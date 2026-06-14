// Function-style (free function) version of Tarjan's SCC algorithm.
// Demonstrates: state kept as local variables, recursion via std::function lambda.
// Compare with Tarjan'sStronglyConnectedComponents.cpp (class-based version).

#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>

// Returns sccId[i] = the SCC index that node i belongs to.
// SCC indices are 0..k-1 where k is the total number of SCCs.
std::vector<int> tarjanScc(const std::vector<std::vector<int>>& graph) {
    const int n = graph.size();
    std::vector<int> dfn(n, -1);     // discovery time; -1 means unvisited
    std::vector<int> low(n, -1);     // lowest dfn reachable from subtree
    std::vector<int> sccId(n, -1);   // result: which SCC each node belongs to
    std::vector<bool> inStack(n, false);
    std::stack<int> stk;
    int timer = 0;
    int sccCount = 0;

    // Recursive lambda. std::function is needed because the lambda refers to
    // itself by name (dfs). [&] captures all outer variables by reference,
    // so dfn/low/inStack/stk/timer/sccCount are all accessible and mutable.
    std::function<void(int)> dfs = [&](int u) {
        dfn[u] = low[u] = timer++;
        stk.push(u);
        inStack[u] = true;

        for (int v : graph[u]) {
            if (dfn[v] == -1) {                    // tree edge: v unvisited
                dfs(v);
                low[u] = std::min(low[u], low[v]);
            } else if (inStack[v]) {               // back/cross edge inside stack
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (low[u] == dfn[u]) {                    // u is root of an SCC
            int cur;
            do {
                cur = stk.top(); stk.pop();
                inStack[cur] = false;
                sccId[cur] = sccCount;
            } while (cur != u);
            ++sccCount;
        }
    };

    for (int i = 0; i < n; ++i) {
        if (dfn[i] == -1) dfs(i);
    }

    return sccId;
}

// Minimal usage example.
// Graph:
//   0 -> 1 -> 2 -> 0   (one SCC: {0,1,2})
//   2 -> 3             (3 alone, another SCC: {3})
//   3 -> 4             (4 alone, another SCC: {4})
// Expected sccId: nodes 0,1,2 share one id; 3 has its own; 4 has its own.
int main() {
    std::vector<std::vector<int>> graph(5);
    graph[0] = {1};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {4};
    graph[4] = {};

    std::vector<int> sccId = tarjanScc(graph);

    for (int i = 0; i < (int)sccId.size(); ++i) {
        std::cout << "node " << i << " -> SCC " << sccId[i] << "\n";
    }
    return 0;
}

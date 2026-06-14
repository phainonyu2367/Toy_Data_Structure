// assume the graph is stored in a adjacency list.
#include <vector>
#include <stack>
#include <algorithm>

class SccGetter {
    private:
        int size;
        std::vector<std::vector<int>> graph;
        std::stack<int> dfsStack;
        std::vector<int> dfn;
        std::vector<int> low;
        std::vector<bool> inStack;
        int count;
        int sccIndex;

        void strongConnect(int u) {
            // 初始化u的dfn和count
            dfn[u] = count;
            low[u] = count;
            count += 1;

            dfsStack.push(u);
            inStack[u] = true;
            for (int i = 0; i < graph[u].size(); ++i) {
                if (dfn[graph[u][i]] == -1) {
                    strongConnect(graph[u][i]);
                    low[u] = std::min(low[u], low[graph[u][i]]);
                } else if (inStack[graph[u][i]]) {
                    low[u] = std::min(low[u], dfn[graph[u][i]]);
                }
            }

            int cur;
            if (low[u] == dfn[u]) {
                do {
                    cur = dfsStack.top();
                    dfsStack.pop();
                    inStack[cur] = false;
                    Scc[cur] = sccIndex;
                } while (cur != u);
                sccIndex += 1;
            }
        }

    public:
        std::vector<int> Scc;

        SccGetter(const std::vector<std::vector<int>>& g) {
            graph = g;
            size = graph.size();
            Scc.resize(size, -1);
            dfn.resize(size, -1);
            low.resize(size, -1);
            inStack.resize(size, false);
            sccIndex = 0;
            count = 0;
        }

        void getScc() {
            for (int i = 0; i < size; ++i) {
                if (dfn[i] == -1) {
                    strongConnect(i);
                }
            }    
        }
};
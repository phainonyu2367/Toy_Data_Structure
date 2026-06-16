#include <vector>
#include <queue>
#include <limits>
#include <cassert>

// 用邻接矩阵表示非负加权图；矩阵中的 0 表示两节点之间没有边。
// 返回 edgeTo[]：每个节点在最短路树（SPT）上的父节点索引，根节点为 -1。
std::vector<int> generateShortestPathsTree(const std::vector<std::vector<double>>& graph, int rootIndex) {
    const int vertexNum = static_cast<int>(graph.size());
    assert(rootIndex >= 0 && rootIndex < vertexNum);

    struct Node {
        int index;
        double dist;
    };

    // priority_queue 默认是最大堆；比较器返回 a > b 时即为最小堆
    struct GreaterDist {
        bool operator()(const Node& a, const Node& b) const {
            return a.dist > b.dist;
        }
    };

    const double INF = std::numeric_limits<double>::infinity();
    std::vector<double> dist(vertexNum, INF);
    std::vector<int> edgeTo(vertexNum, -1);
    std::priority_queue<Node, std::vector<Node>, GreaterDist> pq;

    dist[rootIndex] = 0;
    pq.push({rootIndex, 0.0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        // lazy deletion：堆里可能存在同一节点的多个过期距离，丢弃旧的
        if (cur.dist > dist[cur.index]) continue;

        for (int v = 0; v < vertexNum; ++v) {
            double weight = graph[cur.index][v];
            if (weight > 0 && dist[cur.index] + weight < dist[v]) {
                dist[v] = dist[cur.index] + weight;
                edgeTo[v] = cur.index;
                pq.push({v, dist[v]});
            }
        }
    }

    return edgeTo;
}

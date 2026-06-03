#include <vector>
class AdjacencyList {
    private:
        int size;
        std::vector<std::vector<int>> aList;

    public:
        AdjacencyList(int s) {
            size = s;
            aList.resize(size);
        }

        void addEdge(int i, int j) {
            aList[i].push_back(j);
        }
};
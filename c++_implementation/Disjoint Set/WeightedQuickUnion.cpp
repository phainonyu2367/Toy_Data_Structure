class WeightedQuickUnion {
    private:
        int size;
        int* parents;
        int* weight;
        int getRoot(int index) {
            if (parents[index] == -1) {
                return index;
            }
            return getRoot(parents[index]);
        }

    public:
        WeightedQuickUnion(int s) {
            size = s;
            parents = new int[size];
            weight = new int[size];
            for (int i = 0; i < size; ++i) {
                parents[i] = -1;
                weight[i] = 1;
            }
        }

        ~WeightedQuickUnion() {
            delete [] parents;
        }

        void connect(int aIndex, int bIndex) {
            int aRoot = getRoot(aIndex), bRoot = getRoot(bIndex);
            if (aRoot == bRoot) {
                return;
            }
            if (weight[aRoot] >= weight[bRoot]) {
                parents[bRoot] = aRoot;
                weight[aRoot] += weight[bRoot];
            } else {
                parents[aRoot] = bRoot;
                weight[bRoot] += weight[aRoot];
            }
        }

        bool isConnected(int aIndex, int bIndex) {
            return getRoot(aIndex) == getRoot(bIndex);
        }
};
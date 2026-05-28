class QuickFind {
    private:
        int size;
        int* labels;
    public:
        QuickFind(int s) {
            size = s;
            labels = new int[size];
            for (int i = 0; i < size; ++i) {
                labels[i] = i;
            }
        }

        ~QuickFind() {
            delete [] labels;
        }

        void connect(int aIndex, int bIndex) {
            int aLabel = labels[aIndex], bLable = labels[bIndex];
            for (int i = 0; i < size; ++i) {
                if (labels[i] == bLable) {
                    labels[i] = aLabel;
                }
            }
        }

        bool isConnected(int aIndex, int bIndex) {
            return labels[aIndex] == labels[bIndex];
        }
};

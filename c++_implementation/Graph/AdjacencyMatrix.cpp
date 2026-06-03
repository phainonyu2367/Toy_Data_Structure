class AdjacentMatrix {
    private:
        int size;
        int** matrix;
    
        public:
            AdjacentMatrix(int s) {
                size = s;
                matrix = new int*[size];
                for (int i = 0; i < size; ++i) {
                    matrix[i] = new int[size]{0};
                }
            }

            void addEdge(int i, int j) {
                matrix[i][j] = 1;
            }
};
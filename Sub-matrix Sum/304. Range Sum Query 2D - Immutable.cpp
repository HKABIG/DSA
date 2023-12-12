class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = matrix[i][j];
                if (i > 0) prefix[i][j] += prefix[i - 1][j];
                if (j > 0) prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2][col2];
        if (col1 > 0) sum -= prefix[row2][col1 - 1];
        if (row1 > 0) sum -= prefix[row1 - 1][col2];
        if (col1 > 0 && row1 > 0) sum += prefix[row1 - 1][col1 - 1];
        return sum;
    }
};

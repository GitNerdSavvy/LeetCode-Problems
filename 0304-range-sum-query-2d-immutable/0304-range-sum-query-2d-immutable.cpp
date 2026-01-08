class NumMatrix {
public:
    int r, c;
    vector<vector<int>> pf;

    NumMatrix(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        pf.assign(r + 1, vector<int>(c + 1, 0));

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                pf[i][j] = matrix[i - 1][j - 1] + pf[i - 1][j] + pf[i][j - 1] -
                           pf[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pf[row2 + 1][col2 + 1] - pf[row1][col2 + 1] -
               pf[row2 + 1][col1] + pf[row1][col1];
    }
};

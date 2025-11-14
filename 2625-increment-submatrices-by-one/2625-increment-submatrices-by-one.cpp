class Solution {
public:
    vector<vector<int>> rangeAddQueries(int m, vector<vector<int>>& queries) {
         vector<vector<int>> mat(m + 1, vector<int>(m + 1, 0));
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            mat[r1][c1] += 1;
            if (c2 + 1 < m) mat[r1][c2 + 1] -= 1;
            if (r2 + 1 < m) mat[r2 + 1][c1] -= 1;
            if (r2 + 1 < m && c2 + 1 < m) mat[r2 + 1][c2 + 1] += 1;
        }
        for (int i = 0; i < m; i++)
            for (int j = 1; j < m; j++)
                mat[i][j] += mat[i][j - 1];
        for (int j = 0; j < m; j++)
            for (int i = 1; i < m; i++)
                mat[i][j] += mat[i - 1][j];
        vector<vector<int>> grid(m, vector<int>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = mat[i][j];
        return grid;
    }
};
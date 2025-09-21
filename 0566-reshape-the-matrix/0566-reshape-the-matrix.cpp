class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if (r * c != n * m) return mat;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(mat[i][j]);
            }
        }
        int idx = 0;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = arr[idx++];
            }
        }
        return ans;
    }
};
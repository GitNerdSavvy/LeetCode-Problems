class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ans;

        for (int d = 0; d < rows + cols - 1; ++d) {
            if (d % 2 == 0) {
                int r = min(d, rows - 1);
                int c = d - r;
                while (r >= 0 && c < cols) {
                    ans.push_back(matrix[r][c]);
                    r--;
                    c++;
                }
            } else {
                int c = min(d, cols - 1);
                int r = d - c;
                while (r < rows && c >= 0) {
                    ans.push_back(matrix[r][c]);
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};
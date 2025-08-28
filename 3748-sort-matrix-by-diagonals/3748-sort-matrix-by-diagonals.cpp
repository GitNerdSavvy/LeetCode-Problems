class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j > i) {
                        if (i < n - 1 && j < n - 1 &&
                            grid[i][j] > grid[i + 1][j + 1]) {
                            swap(grid[i][j], grid[i + 1][j + 1]);
                        }
                    } else {
                        if (i < n - 1 && j < n - 1 &&
                            grid[i][j] < grid[i + 1][j + 1]) {
                            swap(grid[i][j], grid[i + 1][j + 1]);
                        }
                    }
                }
            }
        }
        return grid;
    }
};
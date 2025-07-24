class Solution {
public:
    // int func(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
    //     if(i==0 && j==0) return grid[i][j];
    //     if(i<0 || j<0) return 1e8;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=grid[i][j] + func(grid,dp,i-1,j);
    //     int l=grid[i][j] + func(grid,dp,i,j-1);
    //     return dp[i][j] = min(up,l);

    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // return func(grid,dp,n-1,m-1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[0][0] = grid[0][0];
                else {
                    int left = j > 0 ? dp[i][j - 1] : 1e8;
                    int up = i > 0 ? dp[i - 1][j] : 1e8;
                    dp[i][j] =grid[i][j]+ min(left, up);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
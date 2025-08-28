class Solution {
public:
 vector<vector<int>>dp;
    int dfs(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        if (m <= 0 || n <= 0)
            return 0;
        dp[m][n]= dfs(m - 1, n) + dfs(m, n - 1) ;
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
       dp.assign(m+1,vector<int>(n+1,-1));
        int ans = dfs(m, n);
        return ans;
    }
};
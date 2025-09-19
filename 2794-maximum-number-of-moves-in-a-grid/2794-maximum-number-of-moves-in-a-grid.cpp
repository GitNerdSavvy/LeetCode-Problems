class Solution {
public:
    int n,m;
    int dp[1005][1005];
    vector<vector<int>>dir={{-1,1},{0,1},{1,1}};
    int func(vector<vector<int>>&grid,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans=0;
        for(int d=0;d<3;d++){
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]>grid[i][j]){
                ans=max(ans,1+func(grid,r,c));
            }
        }
        return dp[i][j]= ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){         
                ans=max(ans,func(grid,i,0));           
        }
        return ans;
    }
};
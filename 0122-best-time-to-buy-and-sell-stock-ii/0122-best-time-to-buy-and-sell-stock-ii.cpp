class Solution {
public:
    int dp[30005][2];
    int solve(vector<int>&arr,int i,int n,bool flag){
        if(i>=n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int ans=-1e7;
        ans=solve(arr,i+1,n,flag);
        if(flag){
            ans=max(ans,arr[i]+solve(arr,i+1,n,false));
        }else{
            ans=max(ans,solve(arr,i+1,n,true)-arr[i]);
        }
        return dp[i][flag]= ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,prices.size(),false);
    }
};
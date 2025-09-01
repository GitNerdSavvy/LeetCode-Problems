class Solution {
public:
    int dp[1005][105][2];
    int func(vector<int>& arr,int i,int k,bool flag){
        if(i==arr.size()) return 0;
        if(dp[i][k][flag]!=-1) return dp[i][k][flag];
        int ans=-1e7;
        ans=func(arr,i+1,k,flag);
        if(flag){
            ans=max(ans,arr[i]+func(arr,i+1,k-1,false));
        }else{
            if(k>0){
                ans=max(ans,func(arr,i+1,k,true)-arr[i]);
            }
        }
        return dp[i][k][flag]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return func(prices,0,k,false);
    }
};
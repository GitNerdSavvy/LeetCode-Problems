class Solution {
public:
    int dp[1005];
    int func(vector<int>& arr,int i){
        if(i>=arr.size()) return 0;
        if(dp[i] !=-1) return dp[i];
        int ans=arr[i] + min(func(arr,i+1),func(arr,i+2));
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return min(func(cost,0),func(cost,1));
    }
};
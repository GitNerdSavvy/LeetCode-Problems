class Solution {
public:
    const int mod=1e9+7;
    long long dp[35][1005];
    int m;
    int func(int i,int sum){
        // if(sum==0) return 1;
        if(i==0) return (sum==0);
        if(sum<0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        long long ans=0;
        for(int j=1;j<=m;j++){
           ans=(ans+func(i-1,sum-j))%mod;
        }
        return dp[i][sum] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        m=k;
        memset(dp,-1,sizeof dp);
        return func(n,target);
    }
};
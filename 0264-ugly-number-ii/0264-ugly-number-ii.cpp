class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n,-1);
        dp[0]=1;
        int tw=0,th=0,fi=0;
        for(int i=1;i<n;i++){
            dp[i]=min({dp[tw]*2,dp[th]*3,dp[fi]*5});
            if(dp[i] == 2*dp[tw]) tw++;
            if(dp[i] == 3*dp[th]) th++;
            if(dp[i] == 5*dp[fi]) fi++;
        }
        return dp[n-1];
    }
};
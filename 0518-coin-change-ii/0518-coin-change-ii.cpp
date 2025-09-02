class Solution {
public:
    int dp[305][5005];
    int func(int amt,vector<int>&coins,int i){
        if(amt==0) return 1;
        if(i==coins.size()) return 0;
        if(dp[i][amt] !=-1) return dp[i][amt];
        int ans=func(amt,coins,i+1);
        if(coins[i] <= amt){
            ans+=func(amt-coins[i],coins,i) ;
        }
        return dp[i][amt]= ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return func(amount,coins,0);
    }
};
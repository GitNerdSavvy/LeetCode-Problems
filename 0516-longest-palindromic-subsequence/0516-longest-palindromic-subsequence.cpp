class Solution {
public:
    int dp[1005][1005];
    int func(string &s,int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] !=-1) return dp[i][j];
        int ans=0;
        if(s[i]==s[j]){
            ans=max(ans,2+func(s,i+1,j-1)); 
        }else{
            ans=max({ans,func(s,i+1,j),func(s,i,j-1)});
        }
        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof dp);
        return func(s,0,s.length()-1);
    }
};
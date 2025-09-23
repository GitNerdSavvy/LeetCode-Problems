class Solution {
public:
    int dp[1005][2005];
    int func(vector<int>&nums,int idx,int d){
        if(idx<0) return 0;
        if(dp[idx][d+1000]!= -1) return dp[idx][d+1000];
        int ans=1;
        for(int j=0;j<idx;j++){
            if(nums[idx]-nums[j]==d){
                ans=max(ans,1+func(nums,j,d));
            }
        }
        return dp[idx][d+1000]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),ans=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
                int d=nums[i]-nums[j];
                ans=max(ans,1+func(nums,j,d));
           }
        }
        return ans;
    }
};
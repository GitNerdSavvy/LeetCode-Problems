class Solution {
public:
int dp[100005];
    bool func(vector<int>&nums,int i){
        if(i==nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        int t=i+nums[i];
        for(int j=i+1;j<=t;j++){
            if(func(nums,j)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return func(nums,0);
    }
};
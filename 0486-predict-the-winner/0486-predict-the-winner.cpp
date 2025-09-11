class Solution {
public:
    int dp[25][25][2];
    int func(vector<int>& nums, int i, int j, bool flag) {
        if (i > j)
            return 0;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];
        if (flag) {
            return dp[i][j][flag]=max(nums[i] + func(nums, i + 1, j, false),
                       nums[j] + func(nums, i, j - 1, false));
        } else {
            return dp[i][j][flag]=min(func(nums, i + 1, j, true), func(nums, i, j - 1, true));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        int sm=accumulate(nums.begin(),nums.end(),0);
        int p1=func(nums,0,n-1,true);
        int p2=sm-p1;
        return p1>=p2;
    }
};
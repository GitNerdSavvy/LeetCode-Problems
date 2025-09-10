class Solution {
public:
int solve(vector<int>& v, int n, int i, vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int eve = v[i] + solve(v, n, i + 2, dp);
        int odd = solve(v, n, i + 1, dp);
        dp[i] = max(eve, odd);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
         vector<int> dp(n, -1);
        int m1=solve(nums,n-1,0,dp);
        dp.assign(n,-1);
        int m2=solve(nums,n,1,dp);
        return max(m1,m2);

    }
};
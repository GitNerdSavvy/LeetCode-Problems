class Solution {
public:
    int dp[5005][2];
    int func(vector<int>& prices, int i, bool flag) {
        if (i >= prices.size())
            return 0;
            if(dp[i][flag] != -1) return dp[i][flag];
        int ans = func(prices, i + 1, flag);
        if (flag) {
            ans = max(ans, prices[i] + func(prices, i + 2,  false));
        } else {
            ans = max(ans, func(prices, i + 1, true) - prices[i]);
        }
        return dp[i][flag] = ans;
    }
    int maxProfit(vector<int>& prices) { 
        memset(dp,-1,sizeof dp);
        return func(prices, 0, false); 
    }
};
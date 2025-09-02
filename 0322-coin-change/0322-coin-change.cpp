class Solution {
public:
    int dp[15][10005];
    int func(vector<int>& coins, int i, int amt) {
        if (amt == 0)
            return 0;
        if (i == coins.size())
            return 1e9;
        if (dp[i][amt] != -1)
            return dp[i][amt];
        int ans = func(coins, i + 1, amt);
        if (coins[i] <= amt) {
           ans = min(ans, 1 + func(coins, i, amt - coins[i]));
        }
        return dp[i][amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int res = func(coins, 0, amount);
        return (res >= 1e9 ? -1 : res);
    }
};
class Solution {
public:
    int func(vector<int>& energy, int k, int i, vector<int>& dp) {
        if (i >= (int)energy.size())
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];
        int res = energy[i];
        if (i + k < (int)energy.size())
            res += func(energy, k, i + k, dp);
        return dp[i] = res;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, func(energy, k, i, dp));
        return ans;
    }
};
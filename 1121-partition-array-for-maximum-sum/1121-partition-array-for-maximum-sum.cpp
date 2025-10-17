class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int maxVal = 0;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                maxVal = max(maxVal, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + maxVal * j);
            }
        }
        return dp[n];
    }
};
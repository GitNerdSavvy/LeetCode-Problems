class Solution {
public:
    // vector<vector<int>> dp;
    // vector<vector<int>> tri;

    // int solve(int r, int c) {
    //     if (r == tri.size())
    //         return 0;
    //     if (dp[r][c] != -1)
    //         return dp[r][c];
    //     return dp[r][c] = tri[r][c] + min(solve(r + 1, c), solve(r + 1, c +
    //     1));
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int r = n - 2; r >= 0; --r) {
            for (int c = 0; c <= r; ++c) {
                dp[c] = triangle[r][c] + min(dp[c], dp[c + 1]);
            }
        }
        return dp[0];
    }
};
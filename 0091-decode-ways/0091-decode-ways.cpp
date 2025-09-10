class Solution {
public:
    int dp[1005];
    int func(string& s, int i, int n) {
        if (i == n)
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ans = func(s, i + 1, n);

        if (i + 1 < n) {
            int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (val >= 10 && val <= 26) {
                ans += func(s, i + 2, n);
            }
        }

        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        memset(dp, -1, sizeof dp);
        return func(s, 0, n);
    }
};
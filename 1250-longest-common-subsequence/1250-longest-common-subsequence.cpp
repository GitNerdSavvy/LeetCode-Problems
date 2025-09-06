class Solution {
public:
    int dp[1005][1005];

    int func(string& s1, string& s2, int i, int j) {
        if (i >= (int)s1.length() || j >= (int)s2.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + func(s1, s2, i + 1, j + 1);
        return dp[i][j] = max(func(s1, s2, i + 1, j), func(s1, s2, i, j + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return func(text1, text2, 0, 0);
    }
};
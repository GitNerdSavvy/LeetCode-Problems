class Solution {
public:
    int n, m;
    int dp[2001][2001];

    bool func(int i, int j, string& s, string& p) {
        if (i >= n && j >= m)
            return true;
        if (j >= m)
            return false;
        if (i >= n) {
            while (j < m && p[j] == '*')
                j++;
            return j == m;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if (p[j] == '*') {
            ans = func(i, j + 1, s, p) || func(i + 1, j, s, p);
        } else {
            if (s[i] == p[j] || p[j] == '?') {
                ans = func(i + 1, j + 1, s, p);
            } else {
                ans = false;
            }
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        memset(dp, -1, sizeof dp);
        return func(0, 0, s, p);
    }
};

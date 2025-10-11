class Solution {
public:
    string s;
    vector<vector<int>> dp;
    bool isPalindrome(int i, int j) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] != s[j])
            return dp[i][j] = false;
        return dp[i][j] = isPalindrome(i + 1, j - 1);
    }
    string longestPalindrome(string str) {
        s=str;
        int n=s.length();
        dp.assign(n, vector<int>(n, -1));

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j) && (j - i + 1 > maxLen)) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
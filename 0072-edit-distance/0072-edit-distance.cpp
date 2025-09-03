class Solution {
public:
    int dp[505][505];
    int func(string s1, string s2, int i, int j) {
        if (i == s1.size())
            return s2.size() - j;
        if (j == s2.size())
            return s1.size() - i;
        if(dp[i][j]!=-1) return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j]= func(s1, s2, i + 1, j + 1);

        return dp[i][j]= min({1 + func(s1, s2, i + 1, j), 1 + func(s1, s2, i + 1, j + 1),
                    1 + func(s1, s2, i, j + 1)});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return func(word1, word2, 0, 0);
    }
};
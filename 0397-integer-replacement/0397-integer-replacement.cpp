class Solution {
    unordered_map<long long, int> ump;
    int solve(long long n) {
        if (n <= 1)
            return 0;
        if (ump.count(n))
            return ump[n];

        int res;
        if ((n & 1) == 0) {
            res = 1 + solve(n >> 1);
        } else {
            if (n == 3 || (n & 3) == 1) {
                res = 1 + solve(n - 1);
            } else {
                res = 1 + solve(n + 1);
            }
        }

        ump[n] = res;
        return res;
    }

public:
    int integerReplacement(int n) { return solve((long long)n); }
};
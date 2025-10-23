class Solution {
public:
    long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i;
    }
    return res;
}
    int uniquePaths(int m, int n) {
        return (int)nCr(m+n-2,n-1);
    }
};
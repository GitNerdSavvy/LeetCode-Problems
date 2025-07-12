class Solution {
public:
    int numTrees(int n) {
       vector<int> cnt(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            int total = 0;
            for (int root = 1; root <= i; root++) {
                total += cnt[root - 1] * cnt[i - root];
            }
            cnt[i] = total;
        }

        return cnt[n];
    }
};
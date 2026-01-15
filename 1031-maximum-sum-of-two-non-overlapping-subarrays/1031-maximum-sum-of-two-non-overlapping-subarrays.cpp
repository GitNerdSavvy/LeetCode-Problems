class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pf[i + 1] = pf[i] + nums[i];
        }

        auto solve = [&](int l, int m) {
            int bestL = 0;
            int res = 0;
            for (int i = l + m; i <= n; i++) {
                bestL = std::max(bestL, pf[i - m] - pf[i - m - l]);
                res = std::max(res, bestL + pf[i] - pf[i - m]);
            }
            return res;
        };

        return std::max(solve(firstLen, secondLen), solve(secondLen, firstLen));
    }
};
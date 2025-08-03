class Solution {
public:
    bool check(int mid, long long n) {
        long long sum = (1LL * mid * (mid + 1)) / 2;
        return sum <= n;
    }

    int arrangeCoins(int n) {
        int l = 1, h = n, ans = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
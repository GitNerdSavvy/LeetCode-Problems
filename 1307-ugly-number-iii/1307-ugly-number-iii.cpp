class Solution {
public:
    #define int64 long long
    int64 lcmCalc(int64 x, int64 y) { return x / __gcd(x, y) * y; }

    int nthUglyNumber(int n, int a, int b, int c) {
        int64 ab = lcmCalc(a, b);
        int64 bc = lcmCalc(b, c);
        int64 ac = lcmCalc(a, c);
        int64 abc = lcmCalc(ab, c);

        int64 left = 1, right = 2e9, ans = -1;

        while (left <= right) {
            int64 mid = left + (right - left) / 2;

            int64 cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc -
                            mid / ac + mid / abc;

            if (cnt >= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return (int)ans;
    }
};
class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) {
        ll l = 0;
        ll h = x;
        ll ans = 0;
        while (l <= h) {
            ll mid = (l + h) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                l = mid + 1;
            } else {

                h = mid - 1;
            }
        }
        return (int)ans;
    }
};
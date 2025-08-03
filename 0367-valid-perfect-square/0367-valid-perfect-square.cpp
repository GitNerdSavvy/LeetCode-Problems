class Solution {
public:
    typedef long long ll;
    bool isPerfectSquare(int num) {
        ll l = 1;
        ll h = num;
        while (l <= h) {
            ll mid = (ll)(l + h) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return false;
    }
};
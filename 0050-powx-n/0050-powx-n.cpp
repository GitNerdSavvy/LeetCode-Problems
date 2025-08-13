class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0.0;
        long long t = n;
        if (t < 0) {
            x = 1 / x;
            t = -t;
        }
        double ans = 1.0;
        while (t > 0) {
            if (t & 1)
                ans *= x;
            x *= x;
            t >>= 1;
        }
        return ans;
    }
};
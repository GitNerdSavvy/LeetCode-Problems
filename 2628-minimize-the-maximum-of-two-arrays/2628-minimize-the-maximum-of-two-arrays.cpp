class Solution {
public:
    #define ll long long
    int gcd(int a, int b) {
        if (!b)
            return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {
        int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
        int t1=uniqueCnt1,t2=uniqueCnt2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int a = mid / divisor1, b = mid / divisor2;
            if (t1 <= mid - a && t2 <= mid - b &&
                t1 + t2 <= (mid - (mid / LCM))) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
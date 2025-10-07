class Solution {
public:
#define ll long long
    int countDigitOne(int n) {
        ll cnt= 0;
        for (ll p = 1; p <= n; p *= 10) {
            ll l = n / (p * 10);
            ll curr = (n / p) % 10;
            ll h = n % p;

            cnt+= l * p;
            if (curr == 1)
                cnt+= h + 1;
            else if (curr > 1)
                cnt+= p;
        }
      return (int)cnt;
    }
};
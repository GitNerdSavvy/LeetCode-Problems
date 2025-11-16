class Solution {
public:
    const long long mod = 1e9 + 7;
    int numSub(string s) {
        long long ans = 0;
        int cnt = 0;
        for (auto it : s) {
            if (it == '1') {
                cnt++;
            } else {
                long long temp = (cnt + 1)%mod * cnt%mod / 2 % mod;
                ans += temp % mod;
                cnt = 0;
            }
        }
        long long temp = (cnt + 1) * cnt / 2 % mod;
        ans += temp % mod;

        return ans;
    }
};
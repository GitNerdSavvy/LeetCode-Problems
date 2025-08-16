class Solution {
public:
    typedef long long ll;
    bool check(ll mid, vector<int> ranks, int cars) {
        ll cnt = 0;
        for (int it : ranks) {
            if (mid < it)
                continue;
            ll k = (ll)floor(sqrt((long double)mid / (long double)it));
            cnt += k;
            if (cnt >= cars)
                return true;
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1;
        ll h = *min_element(ranks.begin(), ranks.end()) * 1ll * cars * cars;
        ll ans = 0;
        while (l <= h) {
            ll mid = l + (h - l) / 2;
            if (check(mid, ranks, cars)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
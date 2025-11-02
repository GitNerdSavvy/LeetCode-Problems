class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<bool> v(n + 1, true);
        v[0] = v[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (v[i]) {
                for (int j = i * i; j <= n; j += i) {
                    v[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (v[i]) {
                int s = i * i;
                if (s >= l && s <= r) {
                    cnt++;
                }
            }
        }
        int ans = r - l + 1;
        return ans - cnt;
    }
};
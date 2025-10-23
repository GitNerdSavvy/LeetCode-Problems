class Solution {
public:
    bool p(long long n) {
        if (n == 1 or n == 0)
            return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.length();
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            string t = "";
            for (int j = i; j < n; j++) {
                t += s[j];
                if (p(stoll(t))) {
                    v.push_back(stoll(t));
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int m = v.size();
        if (m < 3)
            return accumulate(v.begin(), v.end(), 0ll);
        return v[m - 1] + v[m - 2] + v[m - 3];
    }
};
class Solution {
public:
    // const int mx = 1e6;
    vector<int> closestPrimes(int left, int right) {
        vector<int> arr(right+1, 1);
        arr[0] = arr[1] = 0;

        for (int i = 2; i * i < right+1; i++) {
            if (arr[i]) {
                for (int j = i * i; j < right+1; j += i) {
                    arr[j] = 0;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (arr[i]) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int mn = INT_MAX;
        vector<int> ans = {-1, -1};

        for (int i = 1; i < primes.size(); ++i) {
            int t = primes[i] - primes[i - 1];
            if (t < mn) {
                mn = t;
                ans = {primes[i - 1], primes[i]};
            }
        }

        return ans;
    }
};
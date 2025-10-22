class Solution {
public:
#define mx 10000001
    bool prime[mx];

    void sieve() {
        fill(prime, prime + mx, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < mx; i++) {
            if (prime[i]) {
                for (int j = i * i; j < mx; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    bool paline(const string& s) {
        int l = 0, h = s.size() - 1;
        while (l < h) {
            if (s[l++] != s[h--])
                return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        sieve();
        if (n >= 9989900)
            return 100030001;
        for (int i = n; i < mx; i++) {
            if (prime[i] && paline(to_string(i)))
                return i;
        }
        return -1;
    }
};
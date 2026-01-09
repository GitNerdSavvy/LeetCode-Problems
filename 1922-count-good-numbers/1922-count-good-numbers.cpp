class Solution {
public:
    const int mod = 1e9 + 7;
    long long power(long long a, long long n) {
        long long result = 1 % mod;
        a %= mod;

        while (n > 0) {
            if (n & 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (power(5, n / 2 + n % 2) * power(4, n / 2)) % mod;
    }
};
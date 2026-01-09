class Solution {
public:
    bool isSquare(long long n) {
        long long x = sqrt(n);
        return x * x == n;
    }
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        for (long long i = 1; i * i <= c; i++) {
            if (isSquare(c - i * i)) {
                return true;
            }
        }
        return false;
    }
};
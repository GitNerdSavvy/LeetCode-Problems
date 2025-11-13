class Solution {
public:
    int func(int n) { return n * (n - 1) / 2; }
    int pivotInteger(int n) {
        int val = n * (n + 1) / 2;
        int x = sqrt(val);
        if (x * x == val)
            return x;
        return -1;
    }
};
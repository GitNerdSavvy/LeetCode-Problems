class Solution {
public:
    bool check(int a) {
        if(a<10) return true;
        while (a > 1) {
            if (a % 10 == 0)
                return false;
            a /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (check(i) && check(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }
};
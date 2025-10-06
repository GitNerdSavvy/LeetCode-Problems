class Solution {
public:
    string func(int n) {
        if (n == 0)
            return "";
        n--;
        return func(n / 26) + char('A' + (n % 26));
    }
    string convertToTitle(int cN) { return func(cN); }
};
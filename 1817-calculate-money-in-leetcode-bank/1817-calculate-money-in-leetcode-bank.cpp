class Solution {
public:
    int totalMoney(int n) {
        int a = n / 7;
        int ans = a * 28;
        ans += (7 * a * (a - 1)) / 2;
        if (n % 7) {
            int t = n % 7;
            int curr = a + 1;
            for (int i = 0; i < t; i++) {
                ans += curr;
                curr++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int __lcm(int a, int b) { return a * b / __gcd(a, b); }
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        typedef long long ll; 
        if(n==1 || n==2) return n;
        for (int i = 0; i < n; i++) {
            long long prod = 1, lcm = nums[i], gcd = nums[i],mx= 100000000000;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if(prod>mx) break;
                lcm = __lcm(lcm, (ll)nums[j]);
                gcd = __gcd(gcd, (ll)nums[j]);
                if (prod == lcm * gcd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
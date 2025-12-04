class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length() - 1;
        int m = num2.length() - 1;
        string ans = "";
        int carry = 0;
        while (n >= 0 || m >= 0 || carry > 0) {
            int sum =
                ((n >= 0) ? num1[n] - '0' : 0) + ((m >= 0) ? num2[m] - '0' : 0)+carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            n--, m--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
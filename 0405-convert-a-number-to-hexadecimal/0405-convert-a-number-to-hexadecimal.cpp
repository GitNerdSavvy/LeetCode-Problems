#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        unsigned int x = num;
        string ans = "";
        string h = "0123456789abcdef";
        while (x) {
            ans += h[x % 16];
            x /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

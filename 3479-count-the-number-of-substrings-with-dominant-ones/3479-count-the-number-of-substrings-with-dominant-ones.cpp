#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> ans;
        for (int x = 0; x < n; x++)
            if (s[x] == '0')
                ans.push_back(x);
        int ones = n - ans.size();
        ans.push_back(n);
        int res = 0, temp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = temp; j < (int)ans.size() - 1; j++) {
                int k = j - temp + 1;
                if (k * k > ones)
                    break;
                int p = ans[j];
                int q = ans[j + 1];
                int cnt1 = p - i - (j - temp);
                if (cnt1 >= k * k)
                    res += q - p;
                else
                    res += max(q - p - (k * k - cnt1), 0);
            }
            if (s[i] == '0')
                temp++;
            else {
                res += ans[temp] - i;
                ones--;
            }
        }
        return res;
    }
};

class Solution {
public:
    string maximumXor(string s, string t) {
        string temp;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                if (cnt0) {
                    cnt0--;
                    temp += '0';
                } else {
                    temp += '1';
                }
            } else {
                if (cnt1) {
                    cnt1--;
                    temp += '1';
                } else {
                    temp += '0';
                }
            }
        }
        string ans;
        for (int i = 0; i < s.length(); i++) {
            int t = (s[i] - '0') ^ (temp[i] - '0');
            ans += (t + '0');
        }
        return ans;
    }
};
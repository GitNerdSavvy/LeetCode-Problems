class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(), res = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cnt++;
            else {
                while (i < n && s[i] != '1') {
                    i++;
                }
                res += cnt;
                cnt++;
            }
        }
        return res;
    }
};
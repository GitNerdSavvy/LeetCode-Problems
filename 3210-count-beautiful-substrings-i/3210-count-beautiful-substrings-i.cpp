class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;

        return false;
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int v = 0, c = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) {
                    v++;
                } else {
                    c++;
                }
                if (v == c && v > 0) {
                    if ((v * v) % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
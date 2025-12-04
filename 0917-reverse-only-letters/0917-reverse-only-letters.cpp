class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        string ans = s;
        int l = 0, h = n - 1;
        while (l < h) {
            while (l < h && !((s[l] >= 'a' && s[l] <= 'z') ||
                              (s[l] >= 'A' && s[l] <= 'Z')))
                l++;
            while (l < h && !((s[h] >= 'a' && s[h] <= 'z') ||
                              (s[h] >= 'A' && s[h] <= 'Z')))
                h--;
            swap(ans[l], ans[h]);
            l++, h--;
        }
        return ans;
    }
};
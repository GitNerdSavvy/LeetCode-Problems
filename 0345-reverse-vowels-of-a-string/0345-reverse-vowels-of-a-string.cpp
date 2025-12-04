class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int l = 0, h = n - 1;
        while (l < h) {
            while (l < h && !isVowel(s[l]))
                l++;
            while (l < h && !isVowel(s[h]))
                h--;
            if (isVowel(s[l]) && isVowel(s[h]))
                swap(s[l], s[h]);
            l++, h--;
        }
        return s;
    }
};
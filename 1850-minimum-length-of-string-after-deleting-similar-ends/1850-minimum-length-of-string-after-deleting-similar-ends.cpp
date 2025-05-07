class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int l=0,h=n-1;
        while(l<h && s[l]==s[h]){
            char ch=s[l];
            while (l <= h && s[l] == ch) {
            l++;
             }
           while (l <= h && s[h] == ch) {
            h--;
             }
        }
        return h-l+1;
    }
};
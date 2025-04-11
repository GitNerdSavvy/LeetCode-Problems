class Solution {
public:
    bool symbol(char s){
        s=tolower(s);
        int a=s;
        if(a>96 && a<123) return true;

        return false;
    }
    string reverseOnlyLetters(string s) {
        int l=0;
        int h=s.length()-1;
        while(l<h){
            while(l<h && !symbol(s[l])) l++;
            while(h>l && !symbol(s[h])) h--;
            swap(s[l],s[h]);
            l++;
            h--;

        }
        return s;
    }
};
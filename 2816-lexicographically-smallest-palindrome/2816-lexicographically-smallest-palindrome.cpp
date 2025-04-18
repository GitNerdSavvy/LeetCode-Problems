class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        int n=s.length();
        while(i<j){
            if(s[i]!=s[j]){
                if(s[i]-'0'<s[j]-'0') {
                    s[j]=s[i];
                }
                else{
                    s[i]=s[j];
                }
            }
            i++;
            j--;
        }
        return s;
    }
};
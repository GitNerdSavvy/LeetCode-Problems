class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])) {
            res += tolower(s[i]);
           }
        }
        string rev=res;
       reverse(res.begin(),res.end());
       return (rev==res);
    }
};
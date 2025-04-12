class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length()<s.length()) return false;
       int j=0;
       for(int i=0;i<t.length() && j<s.length();i++){
            if(t[i]==s[j]){
                j++;
            }
       }
       return (j==s.length());
    }
};
class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int c=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                c++;
               if(c<3) ans+=s[i];
            }else{
                c=1;
                ans+=s[i];
            }
        }
        return ans;
    }
};
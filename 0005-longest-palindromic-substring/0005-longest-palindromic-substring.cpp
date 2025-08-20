class Solution {
public:
    int n;
    string lpaline(string s,int l,int h){
         while(l>=0 && h<n){
              if(s[l]!=s[h]) break;
            l--;
            h++;
        }
       
        return s.substr(l+1,h-1-l);
    }
    string longestPalindrome(string s) {
        int ln=0;
        n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            string s1=lpaline(s,i,i);
            mx(s1,ans,ln);
            string s2=lpaline(s,i,i+1);
            mx(s2,ans,ln);
        }
       return ans;
    }
    void mx(string str,string &ans,int &ln){
            if(str.length() > ln){
                ans=str;
                ln=str.length();
            }
    }
};
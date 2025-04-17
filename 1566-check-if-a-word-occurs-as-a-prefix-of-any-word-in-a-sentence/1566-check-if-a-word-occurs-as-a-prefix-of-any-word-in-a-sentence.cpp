class Solution {
public:
    int isPrefixOfWord(string sen, string s) {
      int n=sen.length();
      int m=s.length();  
      int count=1;
      int i=0;
      while(i<n){
        string res="";
        while(i<n && sen[i]!=' '){
            res+=sen[i];
            i++;
            if(res==s) return count;
        }
        //  if (res.substr(0, m) == s) return count;
        count++;
        i++;
        
      }
      return -1;
    }
};
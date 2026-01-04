class Solution {
public:
    string largestEven(string s) {
        int n=s.length()-1;
       while(n>=0){
        if(s[n]=='1'){
            n--;
        }else{
            break;
        }
       }
        return s.substr(0,n+1);
    }
};
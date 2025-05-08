class Solution {
public:
    string sol(string s){
        int i=0,j=0;
        while(i<s.length()){
            if(s[i]=='#'){
                j=max(0,--j);
            }else{
            s[j]=s[i];
            j++;
            }
            i++;
        }
        return s.substr(0,j);
    }
    bool backspaceCompare(string s, string t) {
           return (sol(s)==sol(t));
    }
};
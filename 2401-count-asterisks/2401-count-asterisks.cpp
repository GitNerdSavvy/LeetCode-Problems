class Solution {
public:
    int countAsterisks(string s) {
        int ans=0;
        int flag=1;
        for(char c:s){
            if(c=='|') flag=-flag;
            if(c=='*' && flag==1) ans++;
        }
        return ans;
    }
};
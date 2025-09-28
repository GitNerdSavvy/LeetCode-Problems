class Solution {
public:
    string convertToBase7(int n) {
        if(n==0) return "0";
        string ans="";
        int num=n;
        if(n<0) num=-num;
        while(num>0){
            int t=num%7;
            ans+=t+'0';
            num/=7;
        }
        if(n<0) ans+='-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
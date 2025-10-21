class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0,t=0;
        reverse(columnTitle.begin(),columnTitle.end());
        for(auto it:columnTitle){
            ans+=(it-'A'+1)*pow(26,t);
            t++;
        }
        return ans;
    }
};
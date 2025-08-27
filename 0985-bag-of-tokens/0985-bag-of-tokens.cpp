class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();

        int l=0,h=n-1;
        int ans=0,mx=0;
        while(l<=h){
            if(tokens[l] <= power){
                power-=tokens[l];
                l++;
                ans++;
                 mx=max(ans,mx);
            }else if(ans>0 ){
                power+=tokens[h];
                h--;
                ans--;
            }else{
                break;
            }
           
        }
        return mx;
    }
};
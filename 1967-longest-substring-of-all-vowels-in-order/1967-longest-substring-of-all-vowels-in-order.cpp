class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.length();
        int cnt=1,ans=0,mxv=1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                cnt++;
               
            }else if(word[i]>word[i-1]){
                cnt++;
                mxv++;
            }else{
                cnt=1,mxv=1;
            }
          if(mxv==5) ans=max(ans,cnt);
        }
        return ans;
    }
};
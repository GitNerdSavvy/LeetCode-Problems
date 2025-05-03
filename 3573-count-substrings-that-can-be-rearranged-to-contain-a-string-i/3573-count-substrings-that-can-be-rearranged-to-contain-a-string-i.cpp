class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int>v2(26,0);
        for(char it:word2){
            v2[it-'a']++;
        }
        vector<int>v1(26,0);
        int l=0,k=word2.length();
        long long ans=0;
        for(int i=0;i<word1.length();i++){
            char temp=word1[i];
            if(v2[temp- 'a']>0 && v1[temp- 'a']<v2[temp-'a']){
                k--;
            }
            v1[temp-'a']++;

            while(k==0){
                ans+=word1.length()-i;
                 char t=word1[l];
            if(v2[t-'a']>0 && v1[t-'a']==v2[t-'a']){
                k++;
               }
                v1[t - 'a']--;
               l++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int count(char t){
       return t=='a' || t=='e' || t=='i' || t=='o' || t=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.length(), maxLen=0;
        // for(int i=0;i<=n-k;i++){
        //     string a=s.substr(i,k);
        //     maxLen=max(maxLen,count(a));
        // }
        int l=0,h=0;
        int t=0;
        while(h<n){
            if(count(s[h])) t++;
            if(h-l==k){
                if(count(s[l])) t--;
            l++;
            }
            maxLen=max(maxLen,t);
            h++;
        }
        return maxLen;
    }
};
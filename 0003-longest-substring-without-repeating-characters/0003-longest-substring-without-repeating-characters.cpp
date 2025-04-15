class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,r=0,maxLen=0;
        vector<int>v(255,-1);
        while(r<n){
            if(v[s[r]]>=l){
                l=v[s[r]]+1;
            }
            v[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};
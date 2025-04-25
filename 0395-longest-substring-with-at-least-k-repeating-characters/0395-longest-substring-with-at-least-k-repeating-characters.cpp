class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        int l=0,j=0,maxLen=0,len=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==k) len++;
            if(len==mp.size()){
               
                maxLen=max(maxLen,j-l+1);
            }
            j++;
            if(j==n){
                mp.clear();
                l++;
                j=l;
                len=0;
            }
        }
        return maxLen;
    }
};
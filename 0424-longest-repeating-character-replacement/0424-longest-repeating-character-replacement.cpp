class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,h=0,maxLen=0,maxFreq=0;
        unordered_map<char,int>mp;
        while(h<s.length()){
            mp[s[h]]++;
            maxFreq=max(maxFreq,mp[s[h]]);
            if((h-l+1)-maxFreq>k){
                mp[s[l]]--;
                l++;
                maxFreq=0;
            }
            if((h-l+1)-maxFreq<=k){
                maxLen=max(maxLen,(h-l+1));
            }
            h++;
        }
        return maxLen;
    }
};
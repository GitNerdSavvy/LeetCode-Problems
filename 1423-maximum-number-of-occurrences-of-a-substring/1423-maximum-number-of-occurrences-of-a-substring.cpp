class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l=0,h=0,maxLen=0;
        unordered_map<char,int>mp;
        unordered_map<string,int>ump;
        while(h<s.length()){
            mp[s[h]]++;
           if((h-l+1)>minSize){
            mp[s[l]]--;
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
           }
        if((h-l+1)==minSize && mp.size()<=maxLetters){
            string sub=s.substr(l,minSize);
            ump[sub]++;
            maxLen=max(maxLen,ump[sub]);
        }
            h++;
        }
        return maxLen;
    }
};
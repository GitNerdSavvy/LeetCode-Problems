class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,count=0;
        unordered_map<char,int>mp={{'a',0},{'b',0},{'c',0}};
        while(r<s.length()){
            mp[s[r]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count+=s.length()-r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        int c=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>96 && word[i]<123){
                mp[word[i]]++;
            
        }
    }
        for(int i=0;i<word.length();i++){
            if(word[i]>64 && word[i]<92 && mp[tolower(word[i])]>=1){
                c++;
                mp[tolower(word[i])]=mp[tolower(word[i])]-500;
            }
        }
        return c;
    }
};
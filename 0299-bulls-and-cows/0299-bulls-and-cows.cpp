class Solution {
public:
    string getHint(string secret, string guess) {
        int i=0;
        int bulls=0,cows=0;
        unordered_map<char,int>mp1,mp2;
        while(i<secret.length()){
            if(secret[i]==guess[i]) bulls++;
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;

            }
            i++;
        }
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                cows+=min(it.second,mp2[it.first]);
            }
        }
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
    
};
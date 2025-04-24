class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
       int n=s.length();
       if(n<10) return ans;
       unordered_map<string,int>mp;
       for(int i=0;i<n-9;i++){
        string t=s.substr(i,10);
        mp[t]++;
       }
       for(auto it : mp){
        if(it.second > 1){
            ans.push_back(it.first);
        }
       }
       return ans;
    }
};
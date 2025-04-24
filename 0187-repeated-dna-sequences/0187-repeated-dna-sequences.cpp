class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
       int n=s.length();
       if(n<10) return ans;
       unordered_map<string,int>mp;
       string t="";
       for(int i=0;i<10;i++){
        t+=s[i];
       }
       mp[t]++;
      int i=0,j=10;
     while(j<n){
        t.erase(t.begin());
        t+=s[j];
        mp[t]++;
        j++;
     }
       for(auto it : mp){
        if(it.second > 1){
            ans.push_back(it.first);
        }
       }
       return ans;
    }
};
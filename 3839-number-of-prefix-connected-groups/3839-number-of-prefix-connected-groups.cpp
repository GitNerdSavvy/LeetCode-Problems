class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>ump;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() >= k) {
                string pref = words[i].substr(0, k);
                ump[pref]++;
            }
        }
        int ans=0;
        for(auto it:ump){
            if(it.second>1){
                ans++;
            }
        }
        return ans;
    }
};
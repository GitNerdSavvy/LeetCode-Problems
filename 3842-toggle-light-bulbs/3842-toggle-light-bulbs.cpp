class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        unordered_map<int,int>ump;
        for(auto it:bulbs){
            ump[it]++;
        }
        for(auto it:ump){
            if(it.second&1) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
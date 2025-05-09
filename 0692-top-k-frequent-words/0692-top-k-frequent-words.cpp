class Solution {
public:
     static bool comp(pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.second>p2.second || (p1.second==p2.second && p1.first<p2.first))
            return true;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>ump;
        for(auto i:words){
            ump[i]++;
        }
        vector<pair<string,int>>v(ump.begin(),ump.end());
        sort(v.begin(),v.end(),comp);
          vector<string> ans;
        for(int i=0; i<k; i++){
             ans.push_back(v[i].first);
        }
        
        return ans;
    }
};
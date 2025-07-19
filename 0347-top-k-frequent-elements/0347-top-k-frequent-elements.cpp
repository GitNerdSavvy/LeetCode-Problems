class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(int i:nums){
            mp[i]++;
        }
        priority_queue<pi,vector<pi>, greater<pi> >pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
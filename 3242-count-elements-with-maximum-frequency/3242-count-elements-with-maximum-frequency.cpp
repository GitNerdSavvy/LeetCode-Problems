class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(auto it:nums) ump[it]++;
        int mx=0;
        for(auto it:ump) mx=max(mx,it.second);
        int ans=0;
        for(auto it:ump) {
            if(it.second==mx) ans+=mx;
        }
        return ans;
    }
};
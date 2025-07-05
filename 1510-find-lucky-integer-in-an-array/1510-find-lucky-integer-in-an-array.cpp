class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        unordered_map<int,int>ump;
        for(int it:arr){
            ump[it]++;
        }
        for(auto it:ump){
            if(it.first==it.second) {
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};
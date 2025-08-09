class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0;
        sort(cost.begin(),cost.end(),greater<int>());
        for(int i=cost.size()-1;i>=0;i--){
            if(i%3!=2) ans+=cost[i];
            
        }
        return ans;
    }
};
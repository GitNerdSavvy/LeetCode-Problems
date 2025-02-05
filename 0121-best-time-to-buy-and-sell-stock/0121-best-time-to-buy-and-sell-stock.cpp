class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       
        int maxP=0;
        int currP=0;
        int minV=INT_MAX;
        for(int i=0;i<n;i++){
           minV=min(minV,prices[i]);
           maxP=max(maxP,prices[i]-minV);
        }
       return maxP; 
    }
};
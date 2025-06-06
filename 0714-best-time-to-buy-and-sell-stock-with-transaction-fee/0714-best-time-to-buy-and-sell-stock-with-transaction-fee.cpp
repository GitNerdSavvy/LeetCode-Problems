class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=INT_MIN;
        int sell =0;
        for(int i :prices){
            buy=max(buy, sell-i);
            sell=max(sell,buy+i-fee);
        }
        return sell;
    }
};
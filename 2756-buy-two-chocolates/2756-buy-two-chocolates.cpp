class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int t1=prices[0];
        int t2=prices[1];
        if(t1+t2 <= money){
            return money-t1-t2;
        }else{
            return money;
        }
    }
};
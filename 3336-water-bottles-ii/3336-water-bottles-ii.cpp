class Solution {
public:
    int func(int n,int m){
        if(n<m) return 0;
        return 1+func(n-m+1,m+1);
    }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles+func(numBottles,numExchange);
    }
};
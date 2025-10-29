class Solution {
public:
    int smallestNumber(int n) {
       int t=0;
       while(n){
        t++;
        n>>=1;
       }
       return (int)pow(2,t)-1;
    }
};
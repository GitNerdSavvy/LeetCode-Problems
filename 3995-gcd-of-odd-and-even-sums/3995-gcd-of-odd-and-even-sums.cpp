class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int eve=n*(n+1);
        int odd=n*n;
        return gcd(eve,odd);
    }
};
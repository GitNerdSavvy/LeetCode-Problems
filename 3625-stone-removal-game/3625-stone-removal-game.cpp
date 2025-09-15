class Solution {
public:
    bool canAliceWin(int n) {
        int rem=10;
        int cnt=0;
        while(n>0 && rem<=n){
            n=n-rem;
            rem--;
            cnt++;
        }
        return cnt&1 ? true:false;
    }
};
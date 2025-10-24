class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=0;
        for(int i=0;i<n;i++){
            if(isPrime(nums[i])){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(isPrime(nums[i])){
                h=i;
                break;
            }
        }
        return h-l;
    }
};
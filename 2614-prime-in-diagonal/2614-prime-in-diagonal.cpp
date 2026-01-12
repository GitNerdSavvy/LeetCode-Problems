class Solution {
public:
    bool isPrime(int n){
        if(n==0 || n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans=0;
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==j || i==n-j-1) && isPrime(nums[i][j])){
                    ans=max(ans,nums[i][j]);
                }
            }
        }
        return ans;
    }
};
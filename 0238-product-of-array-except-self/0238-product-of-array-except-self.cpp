class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n,1),sf(n,1);
        for(int i=0;i<n;i++){
            if(i) pf[i]*=pf[i-1];
            pf[i]*=nums[i];
        }
        for(int i= n-1;i>=0;i--){
            if(i!=n-1) sf[i]*=sf[i+1];
            sf[i]*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1){
                ans[i]=pf[i-1]*sf[i+1];
            }else if(i==0){
                ans[i]=sf[i+1];
            }else{
                ans[i]=pf[i-1];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pf(n),sf(n);
        pf[0]=nums[0],sf[n-1]=nums[n-1];
        for(int i=1;i<n;i++) pf[i]=pf[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) sf[i]=sf[i+1]+nums[i];
        for(int i=0;i<n;i++){
            if(pf[i]==sf[i]) return i;
        }
        return -1;
    }
};
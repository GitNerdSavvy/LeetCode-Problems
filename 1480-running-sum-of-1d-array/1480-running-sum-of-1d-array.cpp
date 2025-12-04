class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n);
        for(int i=0;i<n;i++){
            if(i) pf[i]+=pf[i-1];
            pf[i]+=nums[i];
        }
        return pf;
    }
};
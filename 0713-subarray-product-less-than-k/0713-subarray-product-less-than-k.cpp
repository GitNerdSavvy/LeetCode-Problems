class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        if(k<2) return false;
        int sum=1,ans=0;
        for(int i=0;i<n;i++){
            sum*=nums[i];
            while(sum>=k){
                sum=sum/nums[l];
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};
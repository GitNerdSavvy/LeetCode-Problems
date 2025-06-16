class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        int minV=nums[0];
        for(int i=1;i<n;i++){
            int c=nums[i]-minV;
            if(c>0){
                ans=max(ans,c);
                minV=min(minV,nums[i]);
            }
                minV=min(minV,nums[i]);
        }
        return ans;
    }
};
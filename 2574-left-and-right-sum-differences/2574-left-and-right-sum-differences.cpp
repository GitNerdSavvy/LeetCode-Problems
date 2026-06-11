class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=accumulate(nums.begin()+1,nums.end(),0);
        int total=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size()-1;i++){
            ans[i]=abs(sum-curr);
            curr+=nums[i];
            sum-=nums[i+1];
        }
        ans[nums.size()-1]=total-nums[nums.size()-1];
        return ans;
    }
};
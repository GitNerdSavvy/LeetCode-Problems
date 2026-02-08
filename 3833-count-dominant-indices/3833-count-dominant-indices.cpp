class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int ans=0,curr=0;
        for(int i=0;i<nums.size()-1;i++){
            curr+=nums[i];
            if(nums[i]>(sum-curr)/(nums.size()-i-1)) ans++;
        }
        return ans;
    }
};
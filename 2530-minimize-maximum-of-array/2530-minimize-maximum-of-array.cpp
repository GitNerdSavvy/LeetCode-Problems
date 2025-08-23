class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long temp=(sum+i)/(i+1);
            ans=max(ans,temp);
        }
        return ans;
    }
};
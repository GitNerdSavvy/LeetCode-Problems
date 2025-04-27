class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<=nums.size()-2;i++){
            int res=2*(nums[i-1]+nums[i+1]);
            if(res==nums[i])ans++;
        }
        return ans;
    }
};
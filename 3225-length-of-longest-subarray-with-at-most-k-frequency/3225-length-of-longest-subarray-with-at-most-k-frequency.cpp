class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        int n=nums.size(),l=0;
        int ans=0;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
            if(ump[nums[i]]>k){
                while(nums[l]!=nums[i]){
                    ump[nums[l]]--;
                    l++;
                }
                ump[nums[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);

        }
       
        return ans;
    }
};
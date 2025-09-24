class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>ump;
        int ans=0,sum=0;
        ump[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(ump[sum-k]>0) {
                ans+=ump[sum-k];
            }
            ump[sum]++;
        }
        return ans;
    }
};
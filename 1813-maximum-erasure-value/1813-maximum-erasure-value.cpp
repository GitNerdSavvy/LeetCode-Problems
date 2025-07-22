class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, curr = 0;
        unordered_map<int, int> ump;
        int l = 0;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
            curr+=nums[i];
            while(ump[nums[i]]>1){
                ump[nums[l]]--;
                curr -=nums[l];
                l++;
            }
            ans=max(ans,curr);
        }
        

        return ans;
    }
};
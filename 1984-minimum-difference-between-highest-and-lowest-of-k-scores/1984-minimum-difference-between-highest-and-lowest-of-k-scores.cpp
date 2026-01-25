class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        int l = 0, r = k-1;
        while (r < nums.size()) {
           ans=min(ans,abs(nums[r++]-nums[l++]));
        }
        return ans;
    }
};
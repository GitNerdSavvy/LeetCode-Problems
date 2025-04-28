class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         int ans = 0, sum = 1;
         int n = nums.size(), l = 0;
         if(k <= 1) return 0;
       for (int r = 0; r < n; r++) {
           sum *= nums[r];
         while (sum  >= k) {
            sum = sum/nums[l];
            l++;
         }
        ans += (r - l + 1);
     }
       return ans;
    }
};
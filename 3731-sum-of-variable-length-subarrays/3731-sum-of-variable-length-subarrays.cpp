class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> pf(nums.size());
        int sum = 0;
        pf[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pf[i] = nums[i] + pf[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int start = max(0, i - nums[i]);
            if (start == 0)
                ans += pf[i];
            else
                ans += pf[i] - pf[start - 1];
        }
        return ans;
    }
};
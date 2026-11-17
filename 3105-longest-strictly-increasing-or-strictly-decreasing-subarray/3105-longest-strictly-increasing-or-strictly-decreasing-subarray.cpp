class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int in = 1, de = 1, ans = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                in++;
            } else {
                in = 1;
            }

            if (nums[i] < nums[i - 1]) {
                de++;
            } else {
                de = 1;
            }
            ans = max(ans, max(de, in));
        }

        return ans;
    }
};
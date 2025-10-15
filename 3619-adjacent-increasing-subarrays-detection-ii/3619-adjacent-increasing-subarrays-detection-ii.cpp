class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curr = 1, mx = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                curr++;
            else {
                mx = curr;
                curr = 1;
            }
            int h = curr/2;
            int m = min(mx, curr);
            int cnt = max(h, m);
            if (cnt > res)
                res = cnt;
        }
        return res;
    }
};
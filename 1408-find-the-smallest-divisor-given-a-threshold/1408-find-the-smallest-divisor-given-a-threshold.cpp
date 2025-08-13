class Solution {
public:
    bool check(vector<int>& nums, int mid, int t) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + mid - 1) / mid;
        }
        return sum <= t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());

        int ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(nums, mid, threshold)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
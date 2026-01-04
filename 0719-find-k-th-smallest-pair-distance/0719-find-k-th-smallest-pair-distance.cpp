class Solution {
public:
    int check(vector<int>& nums, int mid) {
        int cnt = 0, l = 0;
        for (int i = 1; i < nums.size(); i++) {
            while  (nums[i] - nums[l] > mid) {
                l++;
            }
            cnt += i - l;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int h = nums[n - 1] - nums[0];
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (check(nums, mid) < k) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return l;
    }
};
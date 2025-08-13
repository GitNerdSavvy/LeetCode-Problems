class Solution {
public:
    bool check(vector<int>& arr, int mid, int k) {
        int missing =
            mid - (upper_bound(arr.begin(), arr.end(), mid) - arr.begin());
        return missing >= k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int l = 1;
        int h = max(arr.back(), k + (int)arr.size());
        int ans = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(arr, mid, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool check(vector<int>& nums, long long mid, int totalTrips) {
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += mid / nums[i];
            if (cnt >= totalTrips)
                return true;
        }
        return cnt >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 1;
        long long h =
            1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long ans = 0;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (check(time, mid, totalTrips)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
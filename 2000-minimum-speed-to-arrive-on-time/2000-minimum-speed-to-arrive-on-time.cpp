class Solution {
public:
    bool check(vector<int>& dist, int speed, double hour) {
        long long n = dist.size();
        double time = 0.0;
        for (int i = 0; i < n - 1; i++) {
            time += (dist[i] + speed - 1) / speed; 
            if (time > hour)
                return false;
        }
        time += (double)dist[n - 1] / speed;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1;
        int ans = -1;
        int h = 1e7;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(dist, mid, hour)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
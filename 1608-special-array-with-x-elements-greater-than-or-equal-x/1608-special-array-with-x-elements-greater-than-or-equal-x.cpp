class Solution {
public:
    int check(int mid, vector<int>& nums) {
        int cnt = 0;
        for (auto it : nums) {
            if (it >= mid)
                cnt++;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int l = 0, h = 100;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int t = check(mid, nums);
            if (t == mid)
                return mid;
            else if (t < mid)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
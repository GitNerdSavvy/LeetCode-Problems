class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums)
            total += x;
        int rem = total % p;
        if (rem == 0)
            return 0;

        unordered_map<int, int> ump;
        ump[0] = -1;
        long long prefix = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int curr = prefix % p;
            int need = (curr - rem + p) % p;
            if (ump.count(need)) {
                ans = min(ans, i - ump[need]);
            }
            ump[curr] = i;
        }

        return ans == n ? -1 : ans;
    }
};
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int rec(vector<int>& nums, int idx, int x, int target) {
        if (idx == nums.size()) {
            return (x == target) ? 0 : 1e9;
        }

        if (dp[idx].count(x))
            return dp[idx][x];

        return dp[idx][x] = min({1 + rec(nums, idx + 1, x, target),
                                 rec(nums, idx + 1, x ^ nums[idx], target)});
    }

    int minRemovals(vector<int>& nums, int target) {
        dp.clear();
        int ans = rec(nums, 0, 0, target);

        if (ans == 1e9) {
            return -1;
        } else {
            return ans;
        }
    }
};

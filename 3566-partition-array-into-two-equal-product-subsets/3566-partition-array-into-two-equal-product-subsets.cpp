class Solution {
public:
    typedef __int128 ll;
    bool rec(vector<int>& nums, int idx, ll curr, ll prod) {
        if (curr > prod)
            return false;
        if (idx == nums.size()) {
            return curr == prod;
        }
        return rec(nums, idx + 1, curr * nums[idx] * 1ll, prod) ||
               rec(nums, idx + 1, curr, prod);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll total = 1;
        for (int x : nums) {
            total *= x;
            if (total > (ll)target * target)
                return false;
        }

        if (total != (ll)target * target)
            return false;
        return rec(nums, 0, 1, target);
    }
};
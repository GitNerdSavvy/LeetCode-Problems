class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (ump.count(nums[i]))
                return true;
            ump[nums[i]]++;
            if (i - l >= k) {
                ump[nums[l]]--;
                if (ump[nums[l]] == 0)
                    ump.erase(nums[l]);
                l++;
            }
        }

        return false;
    }
};
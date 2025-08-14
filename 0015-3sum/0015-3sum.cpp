class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, h = n - 1;
            while (l < h) {
                int sum = nums[i] + nums[l] + nums[h];
                if (sum == 0) {
                    res.push_back({nums[l],nums[i],nums[h]});
                    while (l < h && nums[l] == nums[l + 1])
                        l++;
                    while (l < h && nums[h] == nums[h - 1])
                        h--;
                    l++, h--;
                } else if (sum < 0)
                    l++;
                else
                    h--;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> arr;

        for (int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(arr.begin(), arr.end(), nums[i]) -
                      arr.begin();
            ans[i] = pos;
            arr.insert(arr.begin() + pos, nums[i]);
        }
        return ans;
    }
};
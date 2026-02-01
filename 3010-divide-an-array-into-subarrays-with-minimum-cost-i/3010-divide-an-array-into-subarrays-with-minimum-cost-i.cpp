class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if (nums.size() == 3)
            return accumulate(nums.begin(), nums.end(), 0);
        int a = *min_element(nums.begin() + 1, nums.end());
        int b = INT_MAX;
        bool flag = false;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == a && !flag) {
                flag = true;
            } else if (nums[i] <= b) {
                b = nums[i];
            }
        }
        return nums[0]+a+b;
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long mx1 = LLONG_MIN, mx2 = LLONG_MIN, mx3 = LLONG_MIN;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = nums[i];
            } else if (nums[i] < mx1 && nums[i] > mx2) {
                mx3 = mx2;
                mx2 = nums[i];
            } else if (nums[i] < mx2 && nums[i] > mx3) {
                mx3 = nums[i];
            }
        }
        return mx3 == LLONG_MIN ? mx1 : mx3;
    }
};
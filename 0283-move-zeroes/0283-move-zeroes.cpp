class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int h = 1;
        int n = nums.size();
        while (i < h && h < n) {
            if (nums[i] == 0 && nums[h] != 0) {
                swap(nums[i], nums[h]);
                i++;
                h++;
            } else if (nums[i] == 0 && nums[h] == 0) {
                h++;
            } else {
                i++;
                h++;
            }
        }
    }
};
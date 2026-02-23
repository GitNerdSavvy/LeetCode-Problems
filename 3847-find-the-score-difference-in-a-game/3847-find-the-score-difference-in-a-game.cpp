class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int f = 0, s = 0;
        bool flag = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                flag = !flag;
            }
            if ((i + 1) % 6 == 0) {
                flag = !flag;
            }
            if (flag) {
                f += nums[i];
            } else {
                s += nums[i];
            }
        }
        return f - s;
    }
};
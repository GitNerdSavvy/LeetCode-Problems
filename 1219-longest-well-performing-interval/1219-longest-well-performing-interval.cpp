class Solution {
public:
    int func(vector<int>& nums) {
        unordered_map<int, int> sumIndex;
        int sm = 0;
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
            sm += nums[i];

            if (sm > 0) {
                mx = i + 1;
            } else {
                if (sumIndex.find(sm - 1) != sumIndex.end()) {
                    mx = max(mx, i - sumIndex[sm - 1]);
                }
            }

            if (sumIndex.find(sm) == sumIndex.end()) {
                sumIndex[sm] = i;
            }

        }

        return mx;
    }
    int longestWPI(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 8) {
                nums[i] = 1;
            } else {
                nums[i] = -1;
            }
        }
        return func(nums);
    }
};
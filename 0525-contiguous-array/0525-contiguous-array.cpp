class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int it = 0; it < nums.size(); it++) {
            if (nums[it] == 0)
                nums[it] = -1;
        }
        unordered_map<int, int> sumIndex;
        int sm = 0;
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
            sm += nums[i];

            if (sm == 0) {
                mx = i + 1;
            } else if (sumIndex.find(sm) != sumIndex.end()) {
                mx = max(mx, i - sumIndex[sm]);
            } else {
                sumIndex[sm] = i;
            }
        }

        return mx;
    }
};
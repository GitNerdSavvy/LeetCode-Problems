class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> ump, f;
        for (auto it : nums) {
            ump[it]++;
        }
        for (auto it : ump) {
            f[it.second]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (f[ump[nums[i]]] == 1) {
                return nums[i];
            }
        }
        return -1;
    }
};
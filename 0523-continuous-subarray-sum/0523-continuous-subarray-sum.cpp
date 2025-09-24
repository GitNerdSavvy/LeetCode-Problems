class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int t = sum % k;
            if (ump.find(t) != ump.end()) {
                if (i - ump[t] >= 2)
                    return true;
            } else {
                ump[t] = i;
            }
        }
        return false;
    }
};
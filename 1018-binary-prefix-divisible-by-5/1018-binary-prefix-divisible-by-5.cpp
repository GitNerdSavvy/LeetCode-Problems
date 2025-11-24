class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int ans = 0;
        vector<bool> flag;
        for (auto it : nums) {
            ans = ((ans << 1) + it) % 5;
            flag.push_back(ans == 0);
        }
        return flag;
    }
};
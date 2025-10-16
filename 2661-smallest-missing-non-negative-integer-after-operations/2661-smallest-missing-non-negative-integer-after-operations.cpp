class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value, 0);
        for (auto it : nums) {
            v[((it % value) + value) % value]++;
        }
        int res = 0;
        while (v[res % value]--)
            res++;
        return res;
    }
};
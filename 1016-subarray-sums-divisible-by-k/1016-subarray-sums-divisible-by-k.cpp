class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int sum = 0, cnt = 0;
        for (int it : nums) {
            sum += it;
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            if (ump.find(rem) != ump.end()) {
                cnt += ump[rem];
            }
            ump[rem]++;
        }
        return cnt;
    }
};
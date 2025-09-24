class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, cnt = 0;
        unordered_map<int, int> ump;
        ump[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = (sum % k + k) % k;

            if (ump.find(rem) != ump.end()) {
                cnt += ump[rem];
            }
            ump[rem]++;
        }
        return cnt;
    }
};
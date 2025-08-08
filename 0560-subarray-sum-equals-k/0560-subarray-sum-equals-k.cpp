class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int sum = 0, cnt = 0;
        for (int num : nums) {
            sum += num;
            if (ump.find(sum - k) != ump.end()) {
                cnt += ump[sum - k];
            }
            ump[sum]++;
        }
        return cnt;
    }
};
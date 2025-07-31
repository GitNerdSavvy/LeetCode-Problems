class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int& i : nums) {
            i = i % 2;
        }
        unordered_map<int, int> ump;
        ump[0] = 1;

        int sum = 0, cnt = 0;
        for (int i : nums) {
            sum += i;
            if (ump.count(sum - k))
                cnt += ump[sum - k];
            ump[sum]++;
        }
        return cnt;
    }
};
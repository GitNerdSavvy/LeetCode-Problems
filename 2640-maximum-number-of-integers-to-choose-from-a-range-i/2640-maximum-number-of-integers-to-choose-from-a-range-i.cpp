class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        sort(nums.begin(),nums.end());
        int sum = 0,  cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!binary_search(nums.begin(),nums.end(),i)) {
                sum += i;
                if (sum <= maxSum)
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }
};
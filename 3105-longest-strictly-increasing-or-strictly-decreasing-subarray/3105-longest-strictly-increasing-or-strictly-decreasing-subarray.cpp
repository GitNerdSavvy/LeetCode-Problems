class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
                int cnt = 1, t = nums[i];
            for (int j = i+1; j < n; j++) {
                if (nums[j] >t) {
                    cnt++;
                    t = nums[j];
                }else{
                    break;
                }
                    ans = max(ans, cnt);
            }
        }
        for (int i = 0; i < n; i++) {
                int cnt = 1, t = nums[i];
            for (int j = i+1; j < n; j++) {
                if (nums[j] < t) {
                    cnt++;
                    t = nums[j];
                }else{
                    break;
                }
                    ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
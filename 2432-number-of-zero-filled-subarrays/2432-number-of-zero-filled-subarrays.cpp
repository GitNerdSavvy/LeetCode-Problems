class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;
        vector<long long> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            } else if (cnt > 0) {
                res.push_back(1ll*cnt);
                cnt = 0;
            }
        }
        res.push_back(cnt);
        for (auto n : res) {
            cout << n << endl;
            ans += n * (n + 1) / 2;
        }
        return ans;
    }
};
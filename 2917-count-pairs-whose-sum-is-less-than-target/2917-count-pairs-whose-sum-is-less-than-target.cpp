class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            int need = target - arr[i];
            auto it = lower_bound(arr.begin() + i + 1, arr.end(), need);
            ans += (it - (arr.begin() + i + 1));
        }
        return ans;
    }
};
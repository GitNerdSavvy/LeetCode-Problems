class Solution {
public:
    int n;
    int dp[105][105][105];
    int func(vector<int>& arr, int l, int r, int k) {
        if (l > r)
            return 0;

        int l_here = l, k_here = k;

        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        while (l + 1 <= r && arr[l] == arr[l + 1]) {
            l++;
            k++;
        }

        int ans = (k + 1) * (k + 1) + func(arr, l + 1, r, 0);

        for (int i = l + 1; i <= r; i++) {
            if (arr[i] == arr[l]) {
                ans = max(ans,
                          func(arr, i, r, k + 1) + func(arr, l + 1, i - 1, 0));
            }
        }

        return dp[l_here][r][k_here] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        n = boxes.size();
        memset(dp, -1, sizeof dp);
        return func(boxes, 0, n - 1, 0);
    }
};

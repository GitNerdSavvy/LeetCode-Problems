class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = abs(t[i] - s[i]);
        }
        int l = 0, r = 0, csum = 0, mx = 0;
        while (r < n) {
            csum += arr[r];
            while (l <= r && csum > maxCost)
                csum -= arr[l++];
            if (csum <= maxCost)
                mx = max(mx, r - l + 1);
            r++;
        }
        return mx;
    }
};
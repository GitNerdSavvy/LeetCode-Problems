class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3)
            return 0;
        int n = arr.size();
        int mx = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int l = i - 1, h = i + 1;
                while (l > 0 && arr[l - 1] < arr[l]) {
                    l--;
                }
                while (h < n - 1 && arr[h] > arr[h + 1]) {
                    h++;
                }
                mx = max(mx, h - l + 1);
            }
        }
        return mx;
    }
};
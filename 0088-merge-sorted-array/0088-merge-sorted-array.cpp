class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0;
        int h = 0;
        vector<int> ans(m + n);
        int i = 0;

        while (l < m && h < n) {
            if (nums1[l] <= nums2[h]) {
                ans[i++] = nums1[l++];
            } else {
                ans[i++] = nums2[h++];
            }
        }

        while (l < m) {
            ans[i++] = nums1[l++];
        }

        while (h < n) {
            ans[i++] = nums2[h++];
        }

        for (int j = 0; j < m + n; j++) {
            nums1[j] = ans[j];
        }
    }
};
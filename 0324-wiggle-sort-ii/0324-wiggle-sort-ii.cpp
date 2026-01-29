class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> v = nums;
        int small = (n - 1) / 2;
        int large = n - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = v[small--];
            } else {
                nums[i] = v[large--];
            }
        }
    }
};
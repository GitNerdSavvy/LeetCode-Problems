class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        while (k > 1) {
            next_permutation(nums.begin(), nums.end());
            k--;
        }
        string res = "";
        for (int x : nums)
            res += to_string(x);
        return res;
    }
};
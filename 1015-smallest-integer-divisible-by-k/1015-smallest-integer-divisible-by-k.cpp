class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int rem = 1 % k, ans = 1;
        unordered_set<int> vis;
        while (rem != 0) {
            if (vis.count(rem))
                return -1;
            vis.insert(rem);
            rem = (rem * 10 + 1) % k;
            ans++;
        }
        return ans;
    }
};

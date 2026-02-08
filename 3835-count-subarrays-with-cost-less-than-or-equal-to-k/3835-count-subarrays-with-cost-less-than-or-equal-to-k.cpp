class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0, r = 0;
        deque<int> mx, mn;
        long long ans = 0;
        while (r < n) {
            while (!mx.empty() && nums[mx.back()] <= nums[r])
                mx.pop_back();
            mx.push_back(r);

            while (!mn.empty() && nums[mn.back()] >= nums[r])
                mn.pop_back();
            mn.push_back(r);

            while (!mx.empty() && !mn.empty() &&
                   (long long)(nums[mx.front()] - nums[mn.front()]) *
                           (r - l + 1) >
                       k) {

                if (mx.front() == l)
                    mx.pop_front();
                if (mn.front() == l)
                    mn.pop_front();
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
};
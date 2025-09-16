class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        for (int i = 1; i < n; i++) {
            long long x = nums[i];
            while (!st.empty() && gcd(st.top(), x) > 1) {
                long long g = gcd(st.top(), x);
                x = (st.top() / g) * x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
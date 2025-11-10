class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;

        for (int num : nums) {
            while (!st.empty() && num < st.top()) {
                st.pop(); 
            }
            if (st.empty() || num > st.top()) {
                if (num > 0) ans++;
                st.push(num);
            }
        }

        return ans;
    }
};
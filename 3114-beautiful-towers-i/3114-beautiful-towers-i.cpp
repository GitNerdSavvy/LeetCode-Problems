class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
    int n = arr.size();
    long long res = 0;
    int peakIndex = 0;

   
    for (int i = 0; i < n; i++) {
            vector<int> ans(n);
            ans[i] = arr[i];

            // Right side
            if (i + 1 < n) {
                ans[i + 1] = min(arr[i + 1], arr[i]);
                stack<int> st;
                st.push(ans[i + 1]);
                for (int j = i + 2; j < n; j++) {
                    int val = min(arr[j], st.top());
                    ans[j] = val;
                    st.push(val);
                }
            }

            // Left side
            if (i > 0) {
                ans[i - 1] = min(arr[i - 1], arr[i]);
                stack<int> t;
                t.push(ans[i - 1]);
                for (int j = i - 2; j >= 0; j--) {
                    int val = min(arr[j], t.top());
                    ans[j] = val;
                    t.push(val);
                }
            }

            long long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += ans[j];
            }

            res = max(res, sum);
        
    }

    return res;
  }

};
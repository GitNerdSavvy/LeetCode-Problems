class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> psi(n, -1);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) psi[i] = st.top();
            st.push(i);
        }

        stack<int> gt;
        vector<int> nsi(n, n);
        for(int i = n - 1; i >= 0; i--) {
            while(!gt.empty() && arr[gt.top()] >= arr[i]) gt.pop();
            if(!gt.empty()) nsi[i] = gt.top();
            gt.push(i);
        }

        vector<long long> lsum(n, 0);
        lsum[0] = arr[0];
        for(int i = 1; i < n; i++) {
            int ps = psi[i];
            int c = i - ps;
            lsum[i] = c * (long long)arr[i];
            if(ps != -1) lsum[i] += lsum[ps];
        }

        vector<long long> rsum(n, 0);
        rsum[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            int ns = nsi[i];
            int c = ns - i;
            rsum[i] = c * (long long)arr[i];
            if(ns != n) rsum[i] += rsum[ns];
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, lsum[i] + rsum[i] - arr[i]);
        }
        return res;
    }
};
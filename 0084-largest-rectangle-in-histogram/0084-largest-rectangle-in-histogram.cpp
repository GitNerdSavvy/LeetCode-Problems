class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1) return heights[0];
        vector<int>nsi(n);
        nsi[n-1]=n;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
            if(st.empty()) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }
        vector<int>psi(n);
        psi[0]=-1;
        stack<int>t;
        t.push(0);
        for(int i=1;i<n;i++){
            while(!t.empty() && heights[t.top()]>= heights[i]) t.pop();
            if(t.empty()) psi[i] = -1;
            else psi[i] = t.top();
            t.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int area= heights[i]*(nsi[i] - psi[i] - 1);
            maxArea = max(maxArea , area);
        }
        return maxArea;
    }
};
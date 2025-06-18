class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int nsi[n];
        stack<int>st;
        nsi[n-1]=n;
        st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(st.empty()) nsi[i] = n;
        else nsi[i] = st.top();
        st.push(i);
    }
       int psi[n];
       stack<int>tt;
       psi[0]=-1;
       tt.push(0);
    for(int i=1;i<n;i++){
        while(!tt.empty() && arr[tt.top()]>=arr[i]) tt.pop();
        if(tt.empty()) psi[i] = -1;
        else psi[i] = tt.top();
        tt.push(i);
    }
    int maxArea =0;
    for(int i=0;i<n;i++){
        int area = arr[i]*(nsi[i] - psi[i] -1);
        maxArea = max(maxArea, area);
    }
    return maxArea;
    }
};
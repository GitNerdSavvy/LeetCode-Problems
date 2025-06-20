class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ngi(n);
        stack<int>st;
        ngi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) ngi[i] =n;
            else ngi[i] =st.top();
            st.push(i);
        }
        vector<int>ans;
        for(int i=0;i<n-k+1;i++){
            int m=nums[i];
            int j=i;
            while(j <i+k){
                m=nums[j];
                j=ngi[j];
            }
            ans.push_back(m);
        }
        return ans;
    }
};
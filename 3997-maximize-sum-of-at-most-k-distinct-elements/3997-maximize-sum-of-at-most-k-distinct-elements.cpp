class Solution {
public:
    vector<int> maxKDistinct(vector<int>& arr, int k) {
        vector<int>ans;
        set<int>nums(arr.begin(),arr.end());
        priority_queue<int>pq;
        for(int it:nums){
            pq.push(-it);
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(-pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i : nums){
            pq.push(i);
        }
        vector<int>ans;
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            ans.push_back(b);
            ans.push_back(a);
        }
        return ans;
    }
};
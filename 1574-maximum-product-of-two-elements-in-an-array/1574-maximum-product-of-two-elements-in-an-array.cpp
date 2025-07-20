class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            while(pq.size()>2){
                pq.pop();
            }
        }
        int n1=pq.top()-1;
        pq.pop();
        int n2=pq.top()-1;
        return n1*n2;
    }
};
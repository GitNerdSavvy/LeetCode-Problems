class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(int it:amount){
            pq.push(it);
        }
        int ans=0;
        while(pq.top() !=0){
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            t2--,t1--;
            pq.push(t1);
            pq.push(t2);
            ans++;
        }
        return ans;
    }
};
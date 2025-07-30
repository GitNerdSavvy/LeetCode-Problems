class Solution {
public:
    int maximumScore(int a, int b, int c) {
       priority_queue<int>pq;
       pq.push(a); 
       pq.push(b); 
       pq.push(c); 
       int ans=0;
       while(pq.top()>0){
            int t1=pq.top();
            pq.pop();
            if(pq.top()==0){
                break;
            }
            int t2=pq.top();
            pq.pop();
            t1--,t2--;
            pq.push(t1);
            pq.push(t2);
            ans++;
       }
       return ans;
    }
};
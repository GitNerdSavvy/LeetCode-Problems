class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int j = 0; j < tickets.size(); j++) {
            q.push(j);
        }
        int ans=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            tickets[i]--;
            ans++;

            if(tickets[i]==0 && i==k){
                return ans;
            }
            if(tickets[i]>0){
                q.push(i);
            }
        }

        return ans;
    }
};
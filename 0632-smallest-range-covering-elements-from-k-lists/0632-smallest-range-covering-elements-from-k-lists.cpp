class Solution {
public:
    typedef pair<int,pair<int,int>> pip;
    vector<int> smallestRange(vector<vector<int>>& arr) {
       priority_queue<pip,vector<pip>,greater<pip> >pq;
       int mx=INT_MIN;
       for(int i=0;i<arr.size();i++){
            mx=max(mx,arr[i][0]);
            pq.push({arr[i][0],{i,0}});
       } 
       int mn=pq.top().first;
       int l=mn,h=mx;
       while(true){
        int r=pq.top().second.first;
        int c=pq.top().second.second;
        pq.pop();
        if(c==arr[r].size()-1) break;
        pq.push({arr[r][c+1],{r,c+1}});
        mn=pq.top().first;
        mx=max(mx,arr[r][c+1]);
        if(mx-mn < h-l){
            l=mn;
            h=mx;
        }
       }
       return {l,h};
    }
};
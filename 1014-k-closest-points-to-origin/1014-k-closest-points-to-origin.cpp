class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int dis(int x, int y){
        return pow(x,2)+pow(y,2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pii>pq;
        for(int i=0;i<points.size();i++){
            pq.push({dis(points[i][0],points[i][1]),{points[i][0],points[i][1]}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto pnt=pq.top().second;
            ans.push_back({pnt.first,pnt.second});
            pq.pop();
        }
        return ans;
    }
};
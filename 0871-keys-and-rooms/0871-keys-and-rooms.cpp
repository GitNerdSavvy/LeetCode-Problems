class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>us;
        queue<int>q;
        q.push(0);
        us.insert(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            us.insert(curr);
            for(auto it:rooms[curr]){
               if(us.count(it)==0){
                q.push(it);
                us.insert(it);
               }
            }
        }
        return us.size()==rooms.size();
    }
};
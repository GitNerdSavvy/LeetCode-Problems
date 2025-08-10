class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&cnd,int t,int idx,vector<int>&res){
        if(t==0){
            ans.push_back(res);
            return;
        }
        if(idx==cnd.size()) return;

        if(cnd[idx]<=t){
            res.push_back(cnd[idx]);
            solve(cnd,t-cnd[idx],idx,res);
            res.pop_back();
        }

        int j=idx+1;
        // while(j<cnd.size() && cnd[j]==cnd[j-1]) j++;
        solve(cnd,t,j,res);
// committed
    }
    vector<vector<int>> combinationSum(vector<int>& cnd, int target) {
        sort(cnd.begin(),cnd.end());
        vector<int>res;
        ans.clear();
        solve(cnd,target,0,res);
        return ans;
    }
};
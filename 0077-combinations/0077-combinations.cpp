class Solution {
public:
    vector<vector<int> >res;
    void solve(int n,int k,int idx,vector<int>&ans){
        if(ans.size() == k){
            res.push_back(ans);
            return;
        }
        if(idx > n) return;
        if(ans.size()<k){
            ans.push_back(idx);
            solve(n,k,idx+1,ans);
            ans.pop_back();
        }
        // Not pick Condition
        solve(n,k,idx+1,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        res.clear();
        solve(n,k,1,ans);
        return res;
    }
};
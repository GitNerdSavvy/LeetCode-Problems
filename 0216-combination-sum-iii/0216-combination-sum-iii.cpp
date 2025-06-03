class Solution {
public:
   vector<vector<int> >res;
    void solve(int n,int k,int idx,vector<int>&ans){
        if(ans.size() == k && n==0){
            res.push_back(ans);
            return;
        }
        if (ans.size() > k || n < 0 || idx > 9) return;
        
            ans.push_back(idx);
            solve(n-idx,k,idx+1,ans);
            ans.pop_back();
        
        // Not pick Condition
        solve(n,k,idx+1,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        res.clear();
        solve(n,k,1,ans);
        return res;
    }
};
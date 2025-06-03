class Solution {
public:
   vector<vector<int>>res;
    void solve(vector<int>&ans,int idx,int k,int n){
        if (n < 0 || ans.size() > k ) return;
        if(n==0 && ans.size() == k){
            res.push_back(ans);
            return;
        }
        
        for(int j=idx;j<=9;++j){
            ans.push_back(j);
            solve(ans, j+1,k, n-j);
            ans.pop_back();
        }
        
    
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        solve(ans,1,k,n);
        return res;
    }
};
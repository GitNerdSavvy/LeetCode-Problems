class Solution {
public:
    bool prime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        for(int i=2;i<=n/2;i++){
            if(prime(i) && prime(n-i)){
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};
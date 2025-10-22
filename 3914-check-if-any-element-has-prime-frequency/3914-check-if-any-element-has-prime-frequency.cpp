class Solution {
public:
    bool isP(int n){
        if(n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(auto it:nums){
            ump[it]++;
        }
        for(auto it:ump){
            if(isP(it.second)) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        int gc=0;
        for(auto it:nums){
             gc=__gcd(gc,it);
            if(gc==1) return true;
        }
        return false;
    }
};
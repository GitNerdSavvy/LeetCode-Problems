class Solution {
public:
    int minOperations(vector<int>& nums) {
        int t=nums[0];
        for(auto it:nums){
            if(it!=t) return 1;
        }
        return 0;
    }
};
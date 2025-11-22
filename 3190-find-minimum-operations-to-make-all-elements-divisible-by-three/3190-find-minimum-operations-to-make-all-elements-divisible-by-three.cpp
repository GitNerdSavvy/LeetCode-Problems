class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(auto it:nums){
            cnt=cnt+min(it%3,3-it%3);
        }
        return cnt;
    }
};
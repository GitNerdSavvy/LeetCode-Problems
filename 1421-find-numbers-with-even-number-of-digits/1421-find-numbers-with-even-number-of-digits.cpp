class Solution {
public:
    int digCount(int n){
        int c=0;
        if(n<10) return 1;
        return 1+digCount(n/10);
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(digCount(nums[i])%2==0){
                ans++;
            }
        }
        return ans;
    }
};
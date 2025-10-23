class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            long long gc=nums[i];
            for(int j=i;j<n;j++){
                gc=gcd(1ll*nums[j],gc);
                if(gc==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll>>dp(n);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=(ll)nums[i]-(ll)nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    ans+=dp[j][diff];
                }
                dp[i][diff]+=dp[j][diff]+1;
            }
        }
        return (int)ans;
    }
};
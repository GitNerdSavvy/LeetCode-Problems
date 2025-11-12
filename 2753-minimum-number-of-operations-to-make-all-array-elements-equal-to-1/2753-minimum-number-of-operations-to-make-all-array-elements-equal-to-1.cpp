class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
        }
        if(cnt) return n-cnt;

        int ans=200;
        for(int i=0;i<n;i++){
            int gcd=nums[i];
            for(int j=i;j<n;j++){
                gcd=__gcd(gcd,nums[j]);
                if(gcd==1){
                    ans=min(ans,j-i+(n-1));
                }
            }
        }
        return ans==200?-1:ans;
    }

};
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            unordered_set<int>us;
            for(int j=i;j<n;j++){
                cnt+=nums[j];
                us.insert(nums[j]);
                if(us.count(cnt)!=0){
                    ans++;
                }
            }
            us.clear();
        }
        return ans;
    }
};
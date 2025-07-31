class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,sum=0;
        unordered_map<int,int>ump;
        ump[0]=1;
        for(int i:nums){
            sum+=i;
            if(ump.count(sum-goal)) ans+=ump[sum-goal];
            ump[sum]++;
        }
        return ans;
    }
};
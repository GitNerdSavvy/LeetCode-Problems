class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        int mx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                int curr=ump[nums[i]]+ump[nums[i-1]];
                mx=max(mx,curr);
            }
        }
        return mx;
    }
};
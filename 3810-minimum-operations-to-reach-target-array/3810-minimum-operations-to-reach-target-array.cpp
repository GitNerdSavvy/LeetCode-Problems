class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        vector<int>temp(nums.size(),1e9);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target[i]) continue;
            else temp[i]=nums[i];
        }
        set<int>s(temp.begin(),temp.end());
        int ans=0;
        for(auto it:s){
            if(it!=1e9)ans++;
        }
        return ans;
    }
};
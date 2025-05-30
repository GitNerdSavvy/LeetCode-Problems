class Solution {
public:
    void code(vector<int>&nums,vector<int>ans,vector<vector<int>>&res,int index){
        if(index==nums.size()){
            res.push_back(ans);
            return;
        }
        code(nums, ans, res,index+1);
        ans.push_back(nums[index]);
        code(nums, ans, res,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>res;
        code(nums,ans,res,0);
        return res;
    }
};
class Solution {
public:
    void code(vector<int>&nums,vector<int>ans,vector<vector<int>>&res,int index){
        res.push_back(ans);
        for(int i=index;i<nums.size();i++){
            ans.push_back(nums[i]);
            code(nums,ans,res,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>res;
        code(nums,ans,res,0);
        return res;
    }
};
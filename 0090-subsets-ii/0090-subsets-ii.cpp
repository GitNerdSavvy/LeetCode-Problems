class Solution {
public:
    void code(vector<int>&nums,vector<int>ans,vector<vector<int>>&res,int index){
        res.push_back(ans);
        for (int i = index; i < nums.size(); ++i) {
           if (i > index && nums[i] == nums[i - 1]) continue; 
            ans.push_back(nums[i]);
            code(nums, ans, res, i + 1);
            ans.pop_back();
        }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        code(nums,ans,res,0);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>>res;
    void permute(vector<int>&nums, int i, int n){
        if(i==n){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<=n;j++){
            swap(nums[i], nums[j]);
            permute(nums, i+1,n);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0, nums.size()-1);
        return res;
    }
};
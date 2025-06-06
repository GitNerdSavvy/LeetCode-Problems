class Solution {
public:
    vector<vector<int>>res;
    void permute(vector<int>&nums, int i, int n){
        if(i==n){
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int j=i;j<=n;j++){
           if (used.count(nums[j])) continue;
            used.insert(nums[j]);
            swap(nums[i], nums[j]);
            permute(nums, i+1,n);
            swap(nums[i], nums[j]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         permute(nums, 0, nums.size()-1);
         return res;
    }
};
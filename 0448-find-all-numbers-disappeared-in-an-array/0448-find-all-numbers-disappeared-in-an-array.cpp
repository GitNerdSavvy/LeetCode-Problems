class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1),res;
        for(int i=0;i<n;i++){
            ans[nums[i]]=nums[i];
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==0) res.push_back(i);
        }
        return res;
    }
};
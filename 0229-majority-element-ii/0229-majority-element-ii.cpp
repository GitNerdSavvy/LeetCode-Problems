class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n=nums.size();
        map<int,int>ans;
        vector<int>res;
        for(int i=0;i<n;i++){
            ans[nums[i]]++;
        }
        for(auto a:ans){
            if(a.second>n/3){
                res.push_back(a.first);
            }
        }
        return res;
    }
};
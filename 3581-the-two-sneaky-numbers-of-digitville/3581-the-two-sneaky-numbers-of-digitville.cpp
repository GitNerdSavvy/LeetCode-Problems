class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>ump;
        for(auto it:nums)ump[it]++;
        for(auto it:ump){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(auto it:nums){
            res.push_back(it);
        }
        for(auto it:nums){
            res.push_back(it);
        }
        return res;
    }
};
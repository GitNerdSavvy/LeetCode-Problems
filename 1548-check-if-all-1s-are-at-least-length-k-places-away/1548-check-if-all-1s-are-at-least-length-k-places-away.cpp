class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if(k == 0) return true;
        vector<int> idx;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) idx.push_back(i);
        }
        for(int i = 1; i < idx.size(); i++){
            if(idx[i] - idx[i-1] <= k) return false;
        }
        return true;
    }
};

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>s(nums.begin(),nums.end());
        for(int i=0;i<1000;i++){
            if(s.find(original)==s.end()){
                return original;
            }
            original*=2;
        }
        return -1;
    }
};
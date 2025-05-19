class Solution {
public:
    string triangleType(vector<int>& nums) {
    string arr[4]={"none","equilateral","isosceles","scalene"};
    if(nums[0]+nums[1]<=nums[2]) return arr[0];
    if(nums[1]+nums[2]<=nums[0]) return arr[0];
    if(nums[0]+nums[2]<=nums[1]) return arr[0];
        set<int>s;
        for(auto it : nums){
            s.insert(it);
        }
        return arr[s.size()];
    }
};
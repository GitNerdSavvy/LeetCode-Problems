class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    string arr[4]={"none","equilateral","isosceles","scalene"};
    if(nums[0]+nums[1]<=nums[2]) return arr[0];
        set<int>s;
        for(auto it : nums){
            s.insert(it);
        }
        return arr[s.size()];
    }
};
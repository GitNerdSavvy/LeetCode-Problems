class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,c=0;
        while(j<nums.size()){
            if(nums[j]>nums[i]){
                i++;
                c++;
            }
            j++;
        }
        return c;
    }
};
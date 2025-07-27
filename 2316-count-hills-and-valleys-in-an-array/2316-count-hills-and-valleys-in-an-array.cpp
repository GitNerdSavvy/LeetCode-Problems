class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int h=0;
         int i=1,j=0; 
        for(i=1; i<n-1; i++)
        {
            if(nums[j] < nums[i] && nums[i] > nums[i+1]){
                h++;
                j = i;
            }
            else if(nums[j] > nums[i] && nums[i] < nums[i+1]){
                h++;
                j = i;
            }
        }
        return h;
    }
};
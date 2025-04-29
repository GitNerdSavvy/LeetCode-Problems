class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for(auto n:nums){
            if(n==0)z++;
            if(n==1) o++;
            if(n==2) t++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<z)nums[i]=0;
           else if(i>=z && i<z+o)nums[i]=1;
            else{
                nums[i]=2;
            }
        }
    }
};
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return (nums[n-1]*nums[n-2] - nums[0]*nums[1]);
        // ooo n^2 , i hate it------


        int mx1=-1e6,mx2=-1e6;
        int mn1=1e6,mn2=1e6;
        for(auto it:nums){
            if(it>mx1){
                mx2=mx1;
                mx1=it;
            }else if(it>mx2){
                mx2=it;
            }

            if(it<mn1){
                mn2=mn1;
                mn1=it;
            }else if(it<mn2){
                mn2=it;
            }
        }
        return (mx1*mx2 - mn1*mn2);
    }
};
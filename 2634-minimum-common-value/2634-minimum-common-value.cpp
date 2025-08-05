class Solution {
public:
    bool check(vector<int>&arr,int m){
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==m) return true;
            arr[mid]<m?l=mid+1:h=mid-1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            if(check(nums2,nums1[i])) return nums1[i];
        }
        return -1;
    }
};
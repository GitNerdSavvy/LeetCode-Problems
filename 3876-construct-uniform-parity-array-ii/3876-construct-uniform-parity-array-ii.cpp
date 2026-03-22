class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd=1e9;
        for(auto it:nums1){
            if(it&1){
                minOdd=min(minOdd,it);
            }
        }
        if(minOdd==1e9) return true;
        int min=*min_element(nums1.begin(),nums1.end());
        if(min<minOdd) return false;
        return true;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        unordered_map<int,int>ump;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else{
               ump[nums1[i]]++;
               i++,j++;
            }
        }
        for(auto it:ump){
            ans.push_back(it.first);
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,cnt=0,mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt++;
            while(cnt>1){
                if(nums[l]==0) cnt--;
                l++;
            }
            mx=max(mx,i-l+1);
        }
        return mx-1;
    }
};
class Solution {
public:
    bool check(vector<int>& nums,int mid, int k){
        long long sum=0;
        int cnt=1;
        for(int it:nums){
            if(it+sum>mid){
                cnt++;
                sum=it;
                if(cnt>k) return false;
            }else{
                sum+=it;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long l=*max_element(nums.begin(),nums.end());
        long long h=accumulate(nums.begin(),nums.end(),1ll);
        int ans=0;

        while(l<=h){
            long long mid=l+(h-l)/2;
            if(check(nums,mid,k)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
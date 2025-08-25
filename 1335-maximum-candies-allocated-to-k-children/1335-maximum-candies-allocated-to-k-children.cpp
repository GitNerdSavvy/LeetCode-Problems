class Solution {
public:
    bool check(vector<int>&nums,int mid,long long k){
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=1ll*nums[i]/mid;
            if(cnt>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1;
        int h=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(candies,mid,k)){
                ans=max(ans,mid);
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};
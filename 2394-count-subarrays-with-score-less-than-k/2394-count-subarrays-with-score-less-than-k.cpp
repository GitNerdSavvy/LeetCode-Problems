class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    //     long long ans=0;
    //     int n=nums.size();
    //    for(int i=0;i<n;i++){
    //     if(nums[i]<k) ans++;
    //    }
    //    int l=0,h=0;
    //    long long sum=0;
    //    while(l<n && h<n){
    //     int c=2;
    //     // if(l==h)h++;
    //     sum=nums[l];
    //     while(sum<k && h<n){
    //     sum+=(sum/(c-1)+nums[h])*c;
    //    if(sum<k){
    //      h++;
    //     c++;
    //     ans++;
    //    }
    //     }

    //    l++;
    //    h=l+1;

    //    }
     long long ans = 0, sum = 0;
    int n = nums.size(), l = 0;
    for (int r = 0; r < n; r++) {
        sum += nums[r];
        while (sum * (r - l + 1) >= k) {
            sum -= nums[l];
            l++;
        }
        ans += (r - l + 1);
    }
       return ans;
    }
};
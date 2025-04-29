class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size(),count=0,l=0,ans=0;
        long long maxi=*max_element(nums.begin(),nums.end());
        // unordered_map<long long,long long>ump;
        for(long long i=0;i<n;i++){
            if(nums[i]==maxi){
            count++;
            }
           while(count>=k){
               if(nums[l]==maxi) count--;
               l++;
               ans+=n-i;
           }

        }
        return ans;
    }
};
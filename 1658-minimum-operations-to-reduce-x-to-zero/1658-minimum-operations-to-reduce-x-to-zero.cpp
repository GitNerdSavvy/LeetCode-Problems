class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if(accumulate(nums.begin(),nums.end(),0)<x) return -1;
        int t = 0;
        int ans=1e9;
        for (int i = 0; i < n; i++) {
            t += nums[i];
            if (t == x){
                ans=i+1;
                break;
            }
        }
        t = 0;
        for (int i = n - 1; i >= 0; i--) {
            t += nums[i];
            if (t == x){
                ans=min(ans,n-i);
                break;
            }       
        }
        t = 0;
        map<int, int> ump;
        ump[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            t += nums[i];
            ump[t] = i + 1;
        }
        t = 0;
        for (int i = n - 1; i >= 0; i--) {
            t += nums[i];
            if (ump.find(x - t) != ump.end()) {
              ans=min(ans,ump[x - t] + n - i);
            }
        }
        return ans==1e9?-1:ans;
    }
};
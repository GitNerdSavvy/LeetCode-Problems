class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);

            while(dq.front()<i-k+1){
                dq.pop_front();
            }
            if(i>k-2) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
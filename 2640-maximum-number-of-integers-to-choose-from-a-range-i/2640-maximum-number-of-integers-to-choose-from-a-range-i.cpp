class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        // int l = 1;
        // int h = n;
        // //    while(l<=h){
        // //     int mid=(h-l)/2;
        // //     int sum=(mid*(mid+1))/2;
        // //     if(sum)
        // //    }
        int sum = 0,  cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) {
                sum += i;
                if (sum <= maxSum)
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }
};
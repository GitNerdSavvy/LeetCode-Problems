class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, count = 0;
        if (nums.empty()) return 0;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
       auto it = s.begin();
       int prev = *it;
       count = 1;
         ++it;

    for (; it != s.end(); ++it) {
        if (*it == prev + 1) {
            count++;
        } else {
            ans = max(ans, count);
            count = 1;
        }
        prev = *it;
    }

       ans = max(ans, count);
       return ans;
    }
};
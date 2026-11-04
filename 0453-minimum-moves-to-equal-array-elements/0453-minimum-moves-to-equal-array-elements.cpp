class Solution {
    #define all(x) x.begin(),x.end()
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(all(nums),0ll);
        long long min=*min_element(all(nums));
        return (int)sum-min*n;
    }
};
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res(2*n,0);
        int l=0;
        for(int i=0;i<2*n;i+=2){
            res[i]=nums[l++];
        }
        for(int i=1;i<2*n;i+=2){
            res[i]=nums[l++];
        }
        return res;
    }
};
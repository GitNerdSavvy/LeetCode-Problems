class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int n=nums.size();
        int on=0,tw=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                tw=i;
                break;
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                on=nums[i];
                break;
            }
        }
        return {on,tw};
    }
};
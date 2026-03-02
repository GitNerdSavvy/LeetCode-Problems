class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int>fq(101,0);
        for(int i=0;i<nums.size();i++){
            fq[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        int x=nums[0];
        int y=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=x){
                if(fq[nums[i]] !=fq[x]){
                    y=nums[i];
                    break;
                }
            }
        }
        if(y==-1) return {-1,-1};
        return {x,y};
    }
};
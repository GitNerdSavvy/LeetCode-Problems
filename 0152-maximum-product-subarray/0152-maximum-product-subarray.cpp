class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxP=INT_MIN;
        int currP=1;
        for(int i=0;i<n;i++){
            currP=currP*nums[i];
            if(currP>maxP){
                maxP=currP;
            }
            if(currP==0){
                currP=1;
            }
        }
        currP=1;
        for(int i=n-1;i>=0;i--){
            currP*=nums[i];
            maxP=max(maxP,currP);
            if(currP==0) currP=1;
        }
        return maxP;
    }
};
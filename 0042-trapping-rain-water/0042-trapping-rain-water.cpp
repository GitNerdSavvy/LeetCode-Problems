class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       if(n==0 ||n==1) return 0;
       vector<int>lm(n);
      lm[0]=height[0];
       for(int i=1;i<n;i++){
        lm[i]=max(lm[i-1],height[i]);
       } 
       vector<int>rm(n);
       rm[n-1]=height[n-1];
       for(int i=n-2;i>=0;i--){
        rm[i]=max(rm[i+1],height[i]);
       }
       int res;
       for(int i=0;i<n;i++){
            res=res+(min(lm[i],rm[i])-height[i]);
       }
       return res;
    }
};
class Solution {
public:
    int maximumDifference(vector<int>& arr) {
          int n=arr.size();
       int ans=-1;
       int minV=arr[0];
       for(int i=1;i<n;i++){
        int c=arr[i]-minV;
        if(c>0){
             ans=max(ans,c);
             minV=min(minV,arr[i]);
        }
         minV=min(minV,arr[i]);
      
       }
       return ans;
    }
};
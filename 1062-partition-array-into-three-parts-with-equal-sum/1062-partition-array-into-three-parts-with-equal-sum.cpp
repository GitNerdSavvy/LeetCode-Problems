class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int ans=accumulate(arr.begin(),arr.end(),0);
        if(ans%3!=0){
            return false;
        }
        int t=ans/3;
       int csum=0,cnt=0;
       for(int i=0;i<arr.size()-1;i++){
            csum+=arr[i];
            if(csum==t){
                csum=0;
                cnt++;
            }
            if(cnt==2) return true;
       }
       return false;
    }
};
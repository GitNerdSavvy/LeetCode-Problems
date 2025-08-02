class Solution {
public:
    bool check(vector<int>&arr,int mid,int d){
        int cnt=1;
        int m=mid;
        for(int i:arr){
            if(m<i){
                cnt++;
                m=mid;
            }
            m-=i;
        }
       return cnt<=d?1:0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,h=0;
        for(int i:weights){
            l=max(l,i);
            h+=i;
        }
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(weights,mid,days)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(),i=0,j=0,ans=1;
        bool flag=1;
        while(j+1<n){
            if((arr[j]>arr[j+1] && flag==1) || (arr[j]<arr[j+1] && flag==0)){
                flag=!flag;
                ans=max(ans,j-i+2);
                j++;
            }
            else if((arr[j]<arr[j+1] &&flag==1)||(arr[j]>arr[j+1]&&flag==0)){
                flag=!flag;
                i=j;
            }
            else{ 
                j++;
                i=j;
            }
        }
        return ans;
    }
};
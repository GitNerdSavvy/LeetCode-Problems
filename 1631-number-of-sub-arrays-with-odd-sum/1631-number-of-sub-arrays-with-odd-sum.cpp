class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oc=0,pf=0;
        int n=arr.size();
        for(int it:arr){
            pf+=it;
            oc+=pf&1;
        }
        oc+=(n-oc)*oc;
       return oc % 1'000'000'007;
    }
};
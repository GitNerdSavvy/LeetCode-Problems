class Solution {
public:
    bool check(vector<int>&p, int mid,int h){
        int cnt=0;
        for(int i:p){
            if(cnt > h) return 0;
            if(mid>i) cnt++;
            else if(i%mid) cnt+=i/mid +1;
            else cnt+=i/mid; 
        }
        return cnt<=h?1:0;
    }
    int minEatingSpeed(vector<int>& p, int hr) {
        int l = 1, h = 0;
        for (int i : p) {
            h =max(h,i);
        }
        int ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(p, mid, hr)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
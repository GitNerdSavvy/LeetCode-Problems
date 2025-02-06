class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        int m=0;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            if(ans[i-m][1]>=intervals[j][0]){
              ans[i - m][1] = max(intervals[j][1], ans[i - m][1]);
                m++;
            }else{
                ans.push_back({intervals[j][0], intervals[j][1]});
            }
        }
        return ans;
    }
};
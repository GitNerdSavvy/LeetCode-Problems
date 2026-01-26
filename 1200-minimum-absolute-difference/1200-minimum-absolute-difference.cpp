class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mn=1e6;
        int n=arr.size();
        unordered_map<int,int>ump;
        ump[arr[0]]++;
        for(int i=1;i<n;i++){
            ump[arr[i]]++;
            mn=min(mn,arr[i]-arr[i-1]);
        }
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(ump.find(arr[i]-mn)!=ump.end()){
                res.push_back({arr[i]-mn,arr[i]});
            }
        }
        return res;
    }
};
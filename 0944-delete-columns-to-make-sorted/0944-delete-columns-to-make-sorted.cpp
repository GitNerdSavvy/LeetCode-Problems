class Solution {
public:
    bool sorted_str(string s){
        int v='a'-'0';
        for(auto it:s){
            if(v>(it-'0')){
                return false;
            }
            v=it-'0';
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        int n=strs.size();
        int m=strs[0].size();

        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+=strs[j][i];
            }
            cout<<s<<" ";
            if(!sorted_str(s)) cnt++;
        }
        return cnt;
    }
};
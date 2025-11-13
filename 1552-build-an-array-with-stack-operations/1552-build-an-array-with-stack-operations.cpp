class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string a="Push";
        string b="Pop";
        vector<string>ans;
        set<int>s(target.begin(),target.end());
        int m=target.size();
        int z=target[m-1];
        for(int i=1;i<=z;i++){
            if(s.find(i)!=s.end()){
                ans.push_back(a);
            }else{
                ans.push_back(a);
                ans.push_back(b);

            }
        }
        return ans;
    }
};
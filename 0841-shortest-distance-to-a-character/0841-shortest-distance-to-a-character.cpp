class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>res;
        for(int i=0;i<s.length();i++){
            if(s[i]==c){
                res.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            int shortd=INT_MAX;
            for(int j=0;j<res.size();j++){
                shortd=min(shortd,abs(i-res[j]));
            }
            ans.push_back(shortd);
        }
        return ans;
    }
};
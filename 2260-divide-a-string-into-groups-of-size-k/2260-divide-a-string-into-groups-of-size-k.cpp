class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string str;
        for(int i=0;i<s.length();i++){
           str+=s[i];
            if(str.length()==k){
                ans.push_back(str);
                str="";
            }
        }
        if(str.length()!=0){
            for(int i=str.length();i<k;i++){
                str+=fill;
            }
         ans.push_back(str);
        }
         return ans;
    }
};
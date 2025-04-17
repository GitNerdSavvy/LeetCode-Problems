class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=s.length();
        string res="";
        int i=0;
        while(res.size()<n && i<words.size()){
            res+=words[i];
            i++;
            
        }
        if(res==s) return true;

        return false;
    }
};
class Solution {
public:
    bool queryString(string s, int n) {
        string temp="";
        for(int i=1;i<=n;i++){
            string t=bitset<32>(i).to_string();  //no longer recursion function for dec to bit
            temp=t.substr(t.find('1'));
           if(s.find(temp) == std::string::npos) return false;
        }
        return true;
    }
};
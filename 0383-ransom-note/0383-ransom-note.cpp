class Solution {
public:
    bool canConstruct(string r, string m) {
        if(r.length()>m.length()) return false;
        sort(r.begin(),r.end());
        sort(m.begin(),m.end());
        int j=0;
        for(int i=0;i<m.length() && j<r.length();i++){
            if(m[i]==r[j]) j++;
        }
        return (j==r.length());
    }
};
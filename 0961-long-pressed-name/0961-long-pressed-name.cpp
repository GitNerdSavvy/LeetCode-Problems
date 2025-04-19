class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l=0;
        int n=name.length();
        int m=typed.length();
        for(int j=0;j<m;j++){
            if(l<n && name[l]==typed[j]){
                l++;
            }else if(!j || typed[j]!=typed[j-1]) return false;
        }
        return (l==n);
    }
};
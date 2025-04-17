class Solution {
public:
    bool paline(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int h=s.length()-1;
        while(l<h){
            if(s[l]==s[h]){
                l++;
                h--;
            }else{
               return paline(s,l+1,h) || paline(s,l,h-1); 
            }
        }
        return true;
    }
};
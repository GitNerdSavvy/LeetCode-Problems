class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>p;
        int count=0;
        for(auto c:s){
            p[c]++;
           if(p[c]%2==1){
            count++;
           }else{
            count--;
           }
        }
        if(count>1){
            return s.length()-count+1;
        }
        return s.length();
    }
};
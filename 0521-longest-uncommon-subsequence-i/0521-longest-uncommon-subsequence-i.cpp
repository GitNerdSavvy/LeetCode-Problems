class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        // unordered_map<char,int>mp;
        // for(int i=0;i<a.length();i++){
        //     mp[a[i]]++;
        // }
        // int c=0;
        // for(char ch:b){
        //     if(mp.find(c)!=mp.end()){
        //         c++;
        //     }
        // }
        // return (a.length()-c);
         return max(a.size(),b.size());
    }
};
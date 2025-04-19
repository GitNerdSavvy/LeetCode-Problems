class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int n=word1.length();
        int m=word2.length();
        int i=0;
        int j=0;
        int k=n>m?n:m;
        while(i<n || j<m){
            if(i<n ) res+=word1[i];
            if(j<m) res+=word2[j];
            i++;
            j++;
        }
        return res;
    }
};
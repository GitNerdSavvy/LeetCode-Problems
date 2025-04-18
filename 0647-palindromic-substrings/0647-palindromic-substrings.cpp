class Solution {
public:
    int expand(string s,int i,int j){
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int j=i;
            int oddSum=expand(s,i,j);
             j=i+1;
            int evenSum=expand(s,i,j);
            ans+=oddSum+evenSum;
        }
        return ans;
    }
};
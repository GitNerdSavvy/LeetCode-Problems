class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        int n=dict.size();
        int m=s.length();
        int l=0,h=0;
        string res="";
        int ans=0;
        for(int i=0;i<n;i++){
            string temp=dict[i];
            int p=temp.length();
             int l=0,h=0;
            while(h<m){
                if(s[h]==temp[l]){
                    l++;
                    h++;
                }else{
                    h++;
                }
            }
            if(l == p && (p > ans || (p == ans && temp < res))){
                ans=p;
                res=temp;
            }
        }
        return res;
    }
};
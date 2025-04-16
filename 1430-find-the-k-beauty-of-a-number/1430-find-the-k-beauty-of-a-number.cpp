class Solution {
public:
    int divisorSubstrings(int num, int k) {
       int ans=0;
       int i=0;
       int j=0;
       int n=to_string(num).length();
       string str=to_string(num);
       string res="";
       while(j<n){         
            res+=str[j];
           if(j-i+1==k){
                int v=stoi(res);
                if(v!=0 && num%v==0){
                    ans++;
                }
                res.erase(0,1);
                i++;
            }           
            j++;
       }
       return ans;
        
    }
};
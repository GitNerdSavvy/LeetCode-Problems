class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int l=a.length()-1;
        int m=b.length()-1;
        int carry=0;
        while(l>=0 || m>=0 || carry){
            int sum=carry;
            if(l>=0) sum+=a[l--] -'0';
            if(m>=0) sum+=b[m--] -'0';
            res+=(sum%2) +'0';
            carry=sum/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
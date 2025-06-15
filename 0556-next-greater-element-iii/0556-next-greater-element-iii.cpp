class Solution {
public:
    int nextGreaterElement(int ni) {
        string s= to_string(ni);
        int i,j;
        int n=s.length();
        for(i=n-2;i>=0;i--){
            if(s[i] < s[i+1]) break;
        }
        if(i == -1) return -1;
        for(j = n-1; j>=0;j--){
            if(s[j] > s[i]) break;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long long res = stoll(s);
        if(res > INT_MAX) return -1;
        return res;
    }
};
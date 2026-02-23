class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10, 1);
        for (int i = 1; i < 10; i++) {
            fact[i] *= fact[i - 1] * i;
            cout<<fact[i]<<" ";
        }
        string s = to_string(n);
        long long cal = 0;
        for (auto it : s) {
            cal += fact[it - '0'];
        }
        sort(s.begin(),s.end());
        string str=to_string(cal);
        sort(str.begin(),str.end());
        return str==s;
    }
};
class Solution {
public:
    int nextGreaterElement(int n) {
        string ans = to_string(n);
    if (!next_permutation(ans.begin(), ans.end())) return -1;
    long long res = stoll(ans);
    return (res > INT_MAX) ? -1 : res; 
    }
};
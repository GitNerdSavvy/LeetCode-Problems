class Solution {
public:
    // int ans = 0;
    // int func(string s1, string s2, int i, int j) {
    //     if (i == s1.size())
    //         return 0;
    //     if (j == s2.size()) {
    //         j = 0;
    //         ans++;
    //         return 0;
    //     }
    //     if (s1[i] == s2[j]) {
    //         return func(s1, s2, i + 1, j + 1);
    //     } else {
    //         j = 0;
    //         return func(s1, s2, i + 1, j);
    //     }
    //     return ans;
    // }
    int maxRepeating(string sequence, string word) {
        // return func(sequence, word, 0, 0);
        string c=word;
        int count = 0;
        while (sequence.find(c) != string::npos) {
            count++;
            c+=word;
            
        }
        return count;
    }
};
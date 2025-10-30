class Solution {
public:
    bool subseq(string a, string b) {
        int i = 0;
        for (char c : b)
            if (i < a.size() && a[i] == c)
                i++;
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        int mx = -1;

        for (int i = 0; i < strs.size(); i++) {
            bool isSubsequence = false;
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && subseq(strs[i], strs[j])) {
                    isSubsequence = true;
                    break;
                }
            }
            if (!isSubsequence)
                mx = max(mx, (int)strs[i].length());
        }
        return mx;
    }
};
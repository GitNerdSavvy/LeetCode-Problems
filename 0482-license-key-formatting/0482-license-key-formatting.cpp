class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cln;
        for (char c : s) {
            if (c != '-') {
                cln += toupper(c);
            }
        }

        string res;
        int cnt = 0;

        for (int i = cln.size() - 1; i >= 0; --i) {
            res += cln[i];
            cnt++;
            if (cnt == k && i != 0) {
                res += '-';
                cnt = 0;
            }
        }

        reverse(res.begin(), res.end());

        if (!res.empty() && res[0] == '-')
            res.erase(res.begin());

        return res;
    }
};
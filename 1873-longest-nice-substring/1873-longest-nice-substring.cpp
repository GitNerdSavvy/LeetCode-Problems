class Solution {
public:
    bool nice(string t) {
        set<char> s(t.begin(), t.end());
        for (char c : s) {
            if (islower(c)) {
                if (s.count(toupper(c)) == 0)
                    return false;
            } else {
                if (s.count(tolower(c)) == 0)
                    return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string t = "";
            for (int j = i; j < n; j++) {
                t += s[j];
                if (nice(t)) {
                    if (ans.length() < t.length()) {
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};
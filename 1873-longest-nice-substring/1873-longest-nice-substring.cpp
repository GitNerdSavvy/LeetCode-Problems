class Solution {
public:
    string nice(string s) {
        if (s.size() < 2)
            return "";

        set<char> st(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (st.count(tolower(c)) == 0 || st.count(toupper(c)) == 0) {
                string left = nice(s.substr(0, i));
                string right = nice(s.substr(i + 1));
                return left.size() >= right.size() ? left : right;
            }
        }
        return s;
    }
    string longestNiceSubstring(string s) { return nice(s); }
};
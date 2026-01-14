class Solution {
public:
    bool sub(string s, string t) {
        int l = 0, r = 0;
        unordered_map<char, int> cnt;
        unordered_map<char, int> running;
        for (auto it : t)
            cnt[it]++;

        while (r < s.length()) {
            running[s[r]]++;
            if (r - l + 1 > t.length()) {
                running[s[l]]--;
                if (running[s[l]] == 0) {
                    running.erase(s[l]);
                }
                l++;
            }
            if (r - l + 1 == t.length() && running == cnt &&
                s.substr(l, r - l + 1) == t)
                return true;

            r++;
        }
        return false;
    }
    bool queryString(string s, int n) {
        string temp = "";
        for (int i = 1; i <= n; i++) {
            string t =
                bitset<32>(i)
                    .to_string(); // no longer recursion function for dec to bit
            temp = t.substr(t.find('1'));
            if (s.find(temp) == std::string::npos)
                return false;
        }
        return true;
    }
};
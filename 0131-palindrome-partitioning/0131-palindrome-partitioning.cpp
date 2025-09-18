class Solution {
public:
    bool isPa(string s, int j, int i) {
        while (j <= i) {
            if (s[j++] != s[i--])
                return false;
        }
        return true;
    }
    void func(int idx, string s, vector<string>& path,
              vector<vector<string>>& res) {
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPa(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
};
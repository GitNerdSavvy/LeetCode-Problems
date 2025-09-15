class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        unordered_map<char, int> ump;
        for (auto it : brokenLetters)
            ump[it]++;
        stringstream ss(text);
        string w;
        while (ss >> w) {
            bool flag = true;
            for (int i = 0; i < w.length(); i++) {
                if (ump.find(w[i]) != ump.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};
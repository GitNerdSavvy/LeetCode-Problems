class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            int t = 0;
            for (auto it : words[i]) {
                t += weights[it-'a'];
                t %= 26;
            }
            t %= 26;
            ans += char('z'-t);
        }
        return ans;
    }
};
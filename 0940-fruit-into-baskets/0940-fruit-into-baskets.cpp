class Solution {
public:
    int totalFruit(vector<int>& f) {
        int j = 0, len = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < f.size(); i++) {
            ump[f[i]]++;
            while (ump.size() > 2) {
                ump[f[j]]--;
                if (ump[f[j]] == 0) {
                    ump.erase(f[j]);
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};
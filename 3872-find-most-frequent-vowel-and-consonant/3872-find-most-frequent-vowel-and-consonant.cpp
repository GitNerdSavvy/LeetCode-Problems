class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> freqMap;
        for (auto it : s)
            freqMap[it]++;
        int vcnt = 0, cns = 0;
        for (auto it : freqMap) {
            if (isVowel(it.first)) {
                vcnt = max(vcnt, it.second);
            } else
                cns = max(cns, it.second);
        }
        return vcnt + cns;
    }
};
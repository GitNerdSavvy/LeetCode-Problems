class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> ump;
        for (auto it : deck) {
            ump[it]++;
        }
        int g = 0;
        for (auto& p : ump) {
            g = gcd(g, p.second);
        }

        return g >= 2;
    }
};
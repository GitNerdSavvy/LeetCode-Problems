class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center,
                          int radius) {
        int ans = 0;
        int p = 1e9, q = 1e9;
        for (auto it : towers) {
            int a = it[0];
            int b = it[1];
            int c = it[2];
            if (abs(a - center[0]) + abs(b - center[1]) <= radius) {
                if (c > ans ||
                    (c == ans && (p == -1 || a < p || (a == p && b < q)))) {
                    ans = c;
                    p = a;
                    q = b;
                }
            }
        }
        if (p == 1e9) {
            return {-1, -1};
        }
        return {p, q};
    }
};
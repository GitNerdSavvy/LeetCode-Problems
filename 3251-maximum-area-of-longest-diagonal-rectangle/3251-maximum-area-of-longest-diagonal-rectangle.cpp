class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dm) {
        int ans = 0, maxA = 0;
        for (int i = 0; i < dm.size(); i++) {
            int x = dm[i][0];
            int y = dm[i][1];
            int curr = x * x + y * y;
            if (curr > ans || (curr == ans && x * y > maxA)) {
                ans = curr;
                maxA = x * y;
            }
        }
        return maxA;
    }
};
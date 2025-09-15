class Solution {
public:
    int secondHighest(string s) {
        int res[2] = {-1, -1};
        for (auto it : s) {
            int x = it - '0';
            if (x < 10 && x >= 0) {
                if (x > res[0]) {
                    res[1] = res[0];
                    res[0] = x;
                } else if (x != res[0] && x > res[1])
                    res[1] = x;
            }
        }
        return res[1];
    }
};
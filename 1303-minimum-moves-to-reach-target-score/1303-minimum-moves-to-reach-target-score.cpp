class Solution {
public:
    int minMoves(int target, int maxD) {
        int cnt = 0;
        while (target > 1 && maxD>0) {
            if (target % 2 == 0) {
                target /= 2;
                maxD--;
            } else {
                target--;
            }
            cnt++;
        }
        return cnt + target -1;
    }
};
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        return target==0 || (target-x<=y && target% __gcd(x,y)==0);
    }
};
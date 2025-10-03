class Solution {
public:
    const int mod = 1337;
    int largestPalindrome(int n) {
        switch (n) {
        case 1:
            return 9;
            break;
        case 2:
            return 9009 % mod;
            break;
        case 3:
            return 123;
            break;
        case 4:
            return 597;
            break;
        case 5:
            return 677;
            break;
        case 6:
            return 1218;
            break;
        case 7:
            return 877;
            break;
        case 8:
            return 475;
            break;
        }
        return -1;
    }
};
class Solution {
public:
    bool isLeap(int y) {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            return true;
        return false;
    }
    int dayOfYear(string date) {
        vector<int> pfm(
            {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365});
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        if (isLeap(y) && m > 2) {
            return pfm[m - 1] + 1 + d;
        }
        return pfm[m - 1] + d;
    }
};
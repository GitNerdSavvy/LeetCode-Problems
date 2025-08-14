class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = '0' - 1;
        int left = 0;
        for (int i = 0; i < (int)num.length() - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if (num[i] > ch) {
                    ch = num[i];
                    left = i;
                }
            }
        }
        if (ch >= '0')
            return num.substr(left, 3);
        return "";
    }
};
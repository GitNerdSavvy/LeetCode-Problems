class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for (auto it : s) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                v++;
            } else if (isalpha(it)) {
                c++;
            }
        }
        return c == 0 ? 0 : v / c;
    }
};
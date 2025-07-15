class Solution {
public:
    bool isValid(string s) {
         int n = s.length();
        if (n < 3) return false;

        int vw = 0, cs = 0;
        string str = "aeiouAEIOU";

        for (char c : s) {
            if (isalpha(c)) {
                if (str.find(c) != string::npos) {
                    vw++;
                } else {
                    cs++;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }

        return vw >= 1 && cs >= 1;
    }
};
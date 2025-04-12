class Solution {
public:
void removeExtraSpaces(string &s) {
    int n = s.length();
    int i = 0, j = 0;
    
    while (i < n && s[i] == ' ') i++;
    
    bool spaceFound = false;
    while (i < n) {
        if (s[i] != ' ') {
            if (spaceFound) s[j++] = ' ';
            s[j++] = s[i++];
            spaceFound = false;
        } else {
            while (i < n && s[i] == ' ') i++;
            spaceFound = true;
        }
    }
    
    s.resize(j);
}

string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int n = s.length();
    int l = 0;

    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] == ' ') {
            reverse(s.begin() + l, s.begin() + i);
            l = i + 1;
        }
    }

    removeExtraSpaces(s);
    return s;
    }
};